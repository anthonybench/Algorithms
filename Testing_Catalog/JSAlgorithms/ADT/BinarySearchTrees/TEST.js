//=============================================
//=============================================
// Program Entry
// TEST.js
//=============================================
//=============================================
// Dependencies
const bst = require('./BST.js')
const tool = require('./tools.js')



/****************************
  Main
****************************/
tool.border('D');
tool.space(2);

//adding demonstration
tool.border("M");
console.log("     Original Tree")
tool.border("M");
//
myTree = new bst.BST();
myTree.add(11);
myTree.add(5);
myTree.add(3);
myTree.add(7);
myTree.add(2);
myTree.add(4);
myTree.add(6);
myTree.add(8);
myTree.add(16);
// myTree.add(14);
// myTree.add(18);
// myTree.add(13);
// myTree.add(15);
// myTree.add(17);
// myTree.add(19);
myTree.diagnose();


//balance demonstration
tool.space(3);
tool.border("M");
console.log("     Balanced Tree");
tool.border("M");
//
let newRoot = myTree.balance();
myBalancedTree = new bst.BST(newRoot);
myBalancedTree.diagnose();


tool.space(2);
tool.border('D');
//// END ////