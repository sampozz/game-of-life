from random import randint
from copy import deepcopy
import colorama
 

class GameOfLife():

    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.create_world()


    def create_world(self):
        self.world = [
            [
                bool(randint(0, 1)) for y in range(self.width)
            ] for x in range(self.height)
        ]


    def goto_next_gen(self):
        ''' Just one step '''
        next_gen = deepcopy(self.world)
        for x in range(self.height):
            for y in range(self.width):
                next_gen[x][y] = self.live_or_die(x, y)                    
        self.world = deepcopy(next_gen)


    def live_or_die(self, x, y):
        ''' True = live, False = die '''
        is_alive = self.world[x][y]
        count_alive = -1 if is_alive else 0
        for i in range(x-1, x+2):
            for j in range(y-1, y+2):
                if self.world[i % self.height][j % self.width]:
                    count_alive += 1
        if count_alive == 3 or (is_alive and count_alive == 2):
            return True
        return False


    def __str__(self):
        s = ''
        for line in self.world:
            for cell in line:
                char = '*' if cell else ' '
                s += char + ' '
            s += '\n'
        return s


if __name__ == '__main__':
    
    colorama.init()
    game_of_life = GameOfLife(50, 50)
    print("\x1b[2J") # clear terminal screen
    while True:
        print(str(game_of_life))
        game_of_life.goto_next_gen()
        print("\x1b[{};{}H".format(1,1)) # move cursor to 0, 0