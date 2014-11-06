from ROOT import TFile
from PhysicsTools.HeppyCore.statistics.tree import Tree

outfile = TFile('test_tree.root', 'recreate')

tree = Tree('test_tree', 'A test tree')
tree.var('var1')


for i in range(100):
    tree.fill('var1', i)
    tree.tree.Fill()

print 'creating a tree', tree.tree.GetName(),\
      tree.tree.GetEntries(), 'entries in',\
      outfile.GetName()

outfile.Write()