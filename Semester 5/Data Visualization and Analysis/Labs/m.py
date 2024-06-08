import pandas as pd
import itertools
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time
import json
from datetime import date

dict = {"movies":[]}
##################################################################################
class scrap:
	def __init__(self):
		self.driver = webdriver.Chrome(executable_path="E:\chrome_data\chromedriver.exe")
		self.driver.get("https://www.boxofficemojo.com/year/world/?ref_=bo_nb_shs_tab")
		self.start_year = 0
		self.end_year = 0
		self.valid_time = [x for x in range(1900,date.today().year+1)]
	def set_time(self, start_year, end_year):
		self.start_year = start_year
		self.end_year  = end_year
	def start_scraping(self):
		if self.start_year in self.valid_time and self.end_year in self.valid_time and self.start_year < self.end_year :
			self.driver.find_element(By.XPATH, './/*[@id="a-autoid-0-announce"]').click()
			year = int(self.driver.find_element(By.XPATH, './/*[@id="year-navSelector"]/option[1]').text)
			count = self.start_year-1
			for x in range(self.start_year, self.end_year+1):
				path = './/*[@id="year-navSelector"]/option[' + str(year-count) + ']'
				self.driver.find_element(By.XPATH, path).click()
				time.sleep(2)
				for y in range(2,5):
					path =  './/*[@id="table"]/div/table[2]/tbody/tr[' + str(y) +']/td[2]'
					name = self.driver.find_element(By.XPATH, path).text
					print("name: ", name)
					print("year: ", x)
					prev_path = self.driver.current_url
					self.driver.find_element(By.XPATH, path+'/a').click()
					time.sleep(2)
					self.driver.find_element(By.XPATH, './/*[@id="title-summary-refiner"]/a/span').click()
					lst = self.driver.find_element(By.XPATH, './/*[@id="a-page"]/main/div/div[3]/div[4]').text.split("\n")
					for c,v in enumerate(lst):
						if v == "Running Time":
							print("running time: ", lst[c+1])
							running_time = lst[c+1]
						elif v == "Genres":
							print("genre: ", lst[c+1])
							genre = lst[c+1]
					self.driver.get(prev_path)
					dict["movies"].append({"name" : name, "year" : x, "running time" : running_time, "genre" : genre})
				count+=1
		else:
			print("Time is not valid")
		self.driver.close()
#################################################################
s = scrap()
s.set_time(1980,2022)
s.start_scraping()
with open("all_data.json", "w") as outfile:
	json.dump(dict, outfile)