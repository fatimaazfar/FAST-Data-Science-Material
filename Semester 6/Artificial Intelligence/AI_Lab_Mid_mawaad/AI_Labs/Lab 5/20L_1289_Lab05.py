import pygame
import random

BOARD_SIZE = 8
SQUARE_SIZE = 80
SCREEN_WIDTH = BOARD_SIZE * SQUARE_SIZE
SCREEN_HEIGHT = BOARD_SIZE * SQUARE_SIZE

# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GRAY = (150, 150, 150)
RED = (255, 0, 0)

def draw_board(screen, solution):
    for i in range(BOARD_SIZE):
        for j in range(BOARD_SIZE):
            rect = pygame.Rect(j * SQUARE_SIZE, i * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE)
            if (i+j) % 2 == 0:
                pygame.draw.rect(screen, GRAY, rect)
            else:
                pygame.draw.rect(screen, WHITE, rect)

            if solution is not None and solution[i] == j:
                queen_image = pygame.image.load('queen.png')
                queen_image = pygame.transform.scale(queen_image, (SQUARE_SIZE, SQUARE_SIZE))
                screen.blit(queen_image, rect)


def initialize_population(pop_size, board_size):        # initialize population
    population = []
    for i in range(pop_size):
        solution = [random.randint(0, board_size-1) for j in range(board_size)]
        population.append(solution)
    return population

def fitness(solution):                                  # fitness function
    conflicts = 0                                       # number of conflicts
    for i in range(len(solution)):
        for j in range(i+1, len(solution)):             # check for conflicts
            if solution[i] == solution[j]:              # row conflict
                conflicts += 1
            elif abs(solution[i]-solution[j]) == j-i:   # diagonal conflict
                conflicts += 1
    return conflicts                                    # return number of conflicts

def selection(population):                              # selection function
    parent1 = random.choice(population)                 # select two parents 
    parent2 = random.choice(population)                 
    if fitness(parent1) < fitness(parent2):             # return the better parent
        return parent1
    else:
        return parent2

def crossover(parent1, parent2):                        # crossover function
    midpoint = random.randint(1, len(parent1)-1)        # select crossover point
    offspring = parent1[:midpoint] + parent2[midpoint:] # return offspring
    return offspring                                    # return offspring

def mutation(solution, mutation_rate):                  # mutation function
    if random.random() < mutation_rate:                 # mutate with given rate
        pos1 = random.randint(0, len(solution)-1)       # select two positions to swap
        pos2 = random.randint(0, len(solution)-1)       
        solution[pos1], solution[pos2] = solution[pos2], solution[pos1] # swap
    return solution                                    # return mutated solution

def evolve(population, pop_size, mutation_rate, num_generations):               # evolution function
    for generation in range(num_generations):                                   # loop through generations
        offspring_population = []                                               # create offspring population                          
        for i in range(pop_size):
            parent1 = selection(population)
            parent2 = selection(population)                                     # select parents
            offspring = crossover(parent1, parent2)
            offspring = mutation(offspring, mutation_rate)
            offspring_population.append(offspring)                              # create offspring         
        population = sorted(population, key=fitness)                          
        offspring_population = sorted(offspring_population, key=fitness)        # sort population by fitness
        population[:len(offspring_population)] = offspring_population           # replace population with offspring
        if fitness(population[0]) == 0:                                         # check for solution         
            print(f"Solution found after {generation} generations.")            # print solution
            return population[0]
    print(f"No solution found after {num_generations} generations.")            # print no solution
    return None

# def print_board(solution):                                            # print board function    
#     board_size = len(solution)
#     for i in range(board_size):                                       # print board
#         row = ['0' for j in range(board_size)]
#         row[solution[i]] = '1'
#         print(' '.join(row))

# def main():                                                             # main function
#     board_size = 8 # change this to change the board size
#     pop_size = 100
#     mutation_rate = 0.1                                       
#     num_generations = 1000000                                    # set parameters

#     population = initialize_population(pop_size, board_size)                    # initialize population
#     solution = evolve(population, pop_size, mutation_rate, num_generations)     # evolve population
#     if solution is not None:
#         print("Solution:")
#         print_board(solution)
#     else:
#         print("No solution found.")

# if __name__ == '__main__':
#     main()


def main():
    pygame.init()

    # Set up the screen
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

    # title
    pygame.display.set_caption("Eight Queens")

    # Load the queen image
    queen_image = pygame.image.load('queen.png')
    queen_image = pygame.transform.scale(queen_image, (SQUARE_SIZE, SQUARE_SIZE))

    # Initialize the genetic algorithm
    pop_size = 100
    mutation_rate = 0.1
    num_generations = 1000000

    population = initialize_population(pop_size, BOARD_SIZE)

    # Run the genetic algorithm
    solution = None
    for generation in range(num_generations):
        offspring_population = []
        for i in range(pop_size):
            parent1 = selection(population)
            parent2 = selection(population)
            offspring = crossover(parent1, parent2)
            offspring = mutation(offspring, mutation_rate)
            offspring_population.append(offspring)
        population = sorted(population, key=fitness)
        offspring_population = sorted(offspring_population, key=fitness)
        population[:len(offspring_population)] = offspring_population
        solution = population[0]
        if fitness(solution) == 0:
            break

    # Run the Pygame loop
    running = True
    while running:
        # Handle events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        # Draw the board
        screen.fill(BLACK)
        draw_board(screen, solution)

        # Update the screen
        pygame.display.flip()

    pygame.quit()

if __name__ == '__main__':
    main()
