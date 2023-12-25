import networkx as nx
import matplotlib.pyplot as plt

content=open("in.txt").read().splitlines()
relationships = []
for line in content:
    node, connects = line.split(": ")
    connects = connects.split()
    for connect in connects:
        relationships.append((node, connect))
G = nx.Graph()
G.add_edges_from(relationships)
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_color='black', edge_color='gray')
plt.show()
# G.remove_edges_from(#remove edges here)
G.remove_edges_from([("pmn", "kdc"), ("hvm", "grd"), ("jmn", "zfk")])
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_color='black', edge_color='gray')
plt.show()
print(G)
connected_components = list(nx.connected_components(G))
for component in connected_components:
    print(len(component))
