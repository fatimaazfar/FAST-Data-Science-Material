import random

def generate_population(size, n):
    population = []
    for i in range(size):
        chromosome = [0] * n
        for j in range(n):
            chromosome[j] = random.randint(1, n)
        population.append(chromosome)
    return population

def fitness(chromosome):
    conflicts = 0
    for i in range(len(chromosome)):
        for j in range(i+1, len(chromosome)):
            if chromosome[i] == chromosome[j]:
                conflicts += 1
            elif abs(i-j) == abs(chromosome[i]-chromosome[j]):
                conflicts += 1
    return 1 / (conflicts + 1)

def selection(population):
    fitness_values = [fitness(chromosome) for chromosome in population]
    total_fitness = sum(fitness_values)
    probabilities = [fitness_value / total_fitness for fitness_value in fitness_values]
    selected_indices = random.choices(range(len(population)), weights=probabilities, k=2)
    return [population[i] for i in selected_indices]

def crossover(parents):
    n = len(parents[0])
    crossover_point = random.randint(1, n-1)
    child1 = parents[0][:crossover_point] + parents[1][crossover_point:]
    child2 = parents[1][:crossover_point] + parents[0][crossover_point:]
    return [child1, child2]

def mutation(chromosome, mutation_rate):
    for i in range(len(chromosome)):
        if random.random() < mutation_rate:
            chromosome[i] = random.randint(1, len(chromosome))
    return chromosome

def genetic_algorithm(size, n, mutation_rate=0.01, max_generations=1000):
    population = generate_population(size, n)
    for i in range(max_generations):
        new_population = []
        for j in range(size//2):
            parents = selection(population)
            offspring = crossover(parents)
            offspring = [mutation(chromosome, mutation_rate) for chromosome in offspring]
            new_population += offspring
        population = new_population
        if max([fitness(chromosome) for chromosome in population]) == 1:
            return population
    return None

solution = genetic_algorithm(16, 4)
if solution is None:
    print("Failed to converge")
else:
    print("Solution found:")
    print(solution)