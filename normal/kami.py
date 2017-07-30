class Area:
  count = 0

  def __init__(self, color):
    Area.count += 1
    self.id = Area.count
    self.color = color
    self.neighbor = set()

  def connect_with(self, *args):
    for x in args:
      self.neighbor.add(x)
      x.neighbor.add(self)

  def disconnect_from(self, *args):
    for x in args:
      self.neighbor.discard(x)
      x.neighbor.discard(self)

  def dye_to(self, color):
    if self.color == color:
      return False
    old_color = self.color
    self.color = color
    print('Area {} is {} now.'.format(self.id, color))
    for area in self.neighbor:
      if area.color == old_color:
        area.dye_to(color)
    return True

  def __str__(self):
    return 'Area {}, color is {}, connected with {}'.format(self.id, self.color, [x.id for x in self.neighbor])

class Game:
  def __init__(self, color_set, max_dye_time, area_list=[]):
    self.color_set = color_set
    self.max_dye_time = max_dye_time
    self.dye_log = []
    self.map = set(area_list)

  def read_map(self, area):
    self.map = set()
    if area in self.map:
      return
    self.map.add(area)
    for x in area.neighbor:
      self.read_map(x)

  def dye_area(self, area, color):
    if area not in self.map or area.color == color:
      return False
    self.dye_log.append( (area, area.color, color) )
    if area.dye_to(color):
      self.max_dye_time -= 1
      return True
    else:
      self.dye_log.pop()
      return False

  def recall(self, time=1):
    for i in range(0, time):
      area, old_color, new_color = self.dye_log.pop()
      area.dye_to(old_color)
      self.max_dye_time += 1

  def isWin(self):
    color = None
    for area in self.map:
      if color is None:
        color = area.color
      elif area.color != color:
        return False
    return True

  def print_log(self):
    count = 0
    for a, b, c in self.dye_log:
      count += 1
      print('Step {}: dye area {} ({}) to {}'.format(count, a.id, b, c))

def solve_the_game(game):
  if game.isWin():
    return True
  if game.max_dye_time <= 0:
    return False
  for area in game.map:
    for color in game.color_set:
      if game.dye_area(area, color):
        if solve_the_game(game):
          return True
        game.recall()

a = [Area('Red'), Area('Green'), Area('Yellow'), Area('Green'), Area('Yellow'), Area('Red')]
a[0].connect_with(a[1])
a[1].connect_with(a[2])
a[2].connect_with(a[3])
a[3].connect_with(a[4])
a[5].connect_with(a[1])

game = Game(color_set={'Red', 'Green', 'Yellow'}, max_dye_time=3, area_list=a)
for area in game.map:
  print(area)
if solve_the_game(game):
  game.print_log()
for area in game.map:
  print(area)
