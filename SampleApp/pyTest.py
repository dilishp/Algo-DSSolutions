class Zombie:
    created = 0
    #clsmethod
    def zombies_created(cls):
        return Zombie.created

    def __init__(self, name, height):
        self.name = name
        self.height = height
        Zombie.created = 1 + Zombie.created

    def __str__(self):
        return self.name + str(self.height)

class Crawler(Zombie):
    def __init__(self, name, height):
        super().__init__(name = name, height = height)

    def __str__(self):
        return 'Crawler' + super().__str__()

class Jumper(Zombie):
    def __init__(self, name, height):
        super().__init__(name = name, height = height)

    def __str__(self):
        return
        'Jumper'
        + super().__str__()

class Tank(Zombie):
    def __init__(self, name, height):
        super().__init__(name = name, height = height)

    def __str__(self):
        return
        'Tank'
        + super().__str__()


kyleTheCrawler = Crawler(name = 'noLegs', height = 1.9)
jeffTheJumper = Jumper(name = 'taros', height = 1.8)
frankTheTank = Tank(name = 'worf', height = 1.85)

print(str(kyleTheCrawler))
print('Zombies so far? ' + str(Zombie.zombies_created(Zombie)))





