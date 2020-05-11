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

//adding demonstration
tool.border("M");
console.log("List Construction")
tool.border("S");

myList = new lll.LLL();
myList.display();
myList.add(3);
myList.display();
myList.add(1);
myList.display();
myList.add(2);
myList.display();
myList.add(5);
myList.display();
myList.add(4);
myList.diagnose();

//DEBUG
/*
tool.space(2);
tool.border("M");
console.log("*** DEBUG ***")
tool.border("S");

console.log("min: ", myList.getMin());
console.log("max: ", myList.getMax());
myList.remove(3);
myList.remove(1);
myList.clip();
myList.diagnose();
*/

//sorting demonstration (selection sort)
tool.space(2);
tool.border("M");
console.log("List Sort")
tool.border("S");

myList.sort();
myList.diagnose();

//reversal demonstration
tool.space(2);
tool.border("M");
console.log("List Reversal")
tool.border("S");

myList.reverse();
myList.diagnose();

//removing last node demonstration
tool.space(2);
tool.border("M");
console.log("List Destruction")
tool.border("S");

myList.squash();
myList.diagnose();



tool.space(3);
tool.border('D');
//// END ////
