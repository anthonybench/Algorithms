//=============================================
//=============================================
// Program Entry
// TEST.js
//=============================================
//=============================================
// Dependencies
const lll = require('./LLL.js')
const tool = require('./tools.js')



/****************************
  Main
****************************/
tool.border('D');
tool.space(3);

tool.border("M");
console.log("List Construction")
tool.border("S");

//adding domnstration
myList = new lll.LLL();
myList.display();
myList.add(5);
myList.display();
myList.add(4);
myList.display();
myList.add(3);
myList.display();
myList.add(2);
myList.display();
myList.add(1);
myList.display();

tool.space(2);
tool.border("M");
console.log("List Destruction")
tool.border("S");

//removing demonstration
myList.clip();
myList.display();
myList.clip();
myList.display();
myList.clip();
myList.display();
myList.clip();
myList.display();
myList.clip();
myList.display();

tool.space(3);
tool.border('D');
