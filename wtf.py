verteces = [
	[5, 5, "1"],
	[10, 5, "2"],
	[10, 5, "3"],
	[10, 5, "4"],
	[10, 5, "5"],
]

links = {
	"0" : "1",
	"1" : "2",
	"1" : "4",
	"2" : "3",
	"2" : "4",
	"3" : "4",
	"4" : "5",
}
										
level = {s : 0}
parent = {s : None}

i = 1

frontier = [s] <= level i - 1

while frontier:
	next = []
	for u in frontier:
		for v in Adj[u]:







for vert in frontier:
	








class Vertex:

	level = -1

	def __init__(self, x, y, name):
		self.x = x
		self.y = y
		self.name = name

	def __repr__(self):
		return "Vertex : {0}[{1}]".format(self.name, self.level)

	def set_level(self, x):
		self.level = x

	def neighbours(self):




verts = [Vertex(*x) for x in verteces]


print verts