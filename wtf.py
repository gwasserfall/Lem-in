verteces = [
	[5, 5, "1"],
	[10, 5, "2"],
	[10, 5, "3"],
	[10, 5, "4"],
	[10, 5, "5"],
]

links = [
	("1", "2"),
	("1", "4"),
	("2", "3"),
	("2", "4"),
	("3", "4"),
	("4", "5")
]

class Vertex:

	def __init__(self, x, y, name):
		self.x = x
		self.y = y
		self.name = name
		self.neighbours = []
		self.level = 0

	def __repr__(self):
		return "<Vertex {0}>".format(self.name)

	def set_level(self, x):
		self.level = x

	def __eq__(self, name):
		return self.name == name

	def __hash__(self):
		return hash(repr(self))


verts = [Vertex(*x) for x in verteces]

# Fill those neighbours
for v in verts:
	print v, "Connects to",
	for t, f in links:
		if v == f:
			v.neighbours += [x for x in verts if x == t]
		if v == t:
			v.neighbours += [x for x in verts if x == f]
	print v.neighbours	

s = verts[0]

level = {s : 0}
parent = {s : None}

i = 1
frontier = [s]

while frontier:
	next = []
	for u in frontier:
		for v in u.neighbours:
			if v not in level:
				level[v] = i
				parent[v] = u
				next.append(v)
	print "wtf", next
	frontier = next
	i += 1

print level