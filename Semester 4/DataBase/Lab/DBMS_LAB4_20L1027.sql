----------task 1
SELECT
max(Age) as max_age, min(Age) as min_age, avg(Age) as avg_age, stdev(Age) as std_age
from dbo.Users
----------task 2
select FollowedUserName
     , count(FollowerUserName) as totalfollowers
  from Following
group
    by FollowedUserName
having count(FollowerUserName) =
     ( select max(totalfollowers) as highest_total
         from (
              select FollowedUserName
                   , count(FollowerUserName) as totalfollowers
                from Following
              group
                  by FollowedUserName
              ) as t
     )
----------task 3
select top(1)
FollowedUserName as Name,
count(FollowerUserName) as Followers from Following
group by FollowedUserName
order by count(FollowerUserName)
-----------task 4
Select UserName from Users
Except
Select UserName from Tweets
-----------task 5
SELECT Hashtag, UserName, count(UserName) as HashtagsNum
FROM Tweets , Hashtags 
WHERE Tweets.Text LIKE CONCAT('%', Hashtags.Hashtag, '%')
group by UserName,Hashtag
-----------task 6
select *
from (
select distinct UserName
from Tweets, Hashtags
where tweets.Text not like '%#census%') as t
except
Select *
from (
select distinct UserName
from Tweets, Hashtags
where tweets.Text like '%#census%') as b
-----------task 7
select UserName from Users
except
select FollowedUserName from Following
-----------task 8
select UserName from Users
where not exists (select FollowedUserName from Following where UserName = FollowedUserName)
-----------task 9(maximum user count)
select InterestID, count(UserName) as UserCount
  from UserInterests
group
    by InterestID
having count(UserName) =
     ( select max(totalusers) as highest_total
         from (
              select InterestID
                   , count(UserName) as totalusers
                from UserInterests
              group
                  by InterestID
              ) as t
     )
-----------task  9(least user count)
select InterestID, count(UserName) as UserCount
  from UserInterests
group
    by InterestID
having count(UserName) =
     ( select min(totalusers) as highest_total
         from (
              select InterestID
                   , count(UserName) as totalusers
                from UserInterests
              group
                  by InterestID
              ) as t
     )
-----------task 10
select Country, count(TweetID) as NumOfTweets
from Tweets, Users
where Tweets.UserName = Users.UserName
group by Country
-----------task 11
select UserName, count(TweetID) as NumOfTweets
  from Tweets
group
    by UserName
having count(TweetID) >
     ( select avg(totaltweets) as NumOfTweets
         from (
              select UserName
                   , count(TweetID) as totaltweets
                from Tweets
              group
                  by UserName
              ) as t
     )
-----------task 12
select FollowedUserName
from Following, Users
where FollowerUserName = UserName and Country = 'Pakistan'
group by FollowedUserName
-----------task 13
select UserInterests.InterestID, Interests.Description ,count(UserName) as UserCount
  from UserInterests, Interests
where UserInterests.InterestID = Interests.InterestID
group
    by Interests.Description, UserInterests.InterestID
having count(UserName) =
     ( select max(totalusers) as highest_total
         from (
              select InterestID
                   , count(UserName) as totalusers
                from UserInterests
              group
                  by InterestID
              ) as t
     )