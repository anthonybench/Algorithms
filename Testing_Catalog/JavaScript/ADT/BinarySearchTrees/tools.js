//=============================================
//=============================================
// General Utility
// tools.js
//=============================================
//=============================================

// Print Borders
let border = function (c) {
  if (typeof c != "string")
    console.log("Invalid input. Use: 's', 'm', 'l' or 'd'");
  else if (c.toLowerCase() == "s")
    console.log("==============");
  else if (c.toLowerCase() == "m")
    console.log("==========================");
  else if (c.toLowerCase() == "l")
    console.log("===============================================");
  else if (c.toLowerCase() == "d") {
    console.log("===============================================");
    console.log("===============================================");
  }
  return;
};

// Print Whitespace
let space = function (n) {
  if (n < 1)
    console.log("Invalid input. Use int >= 0");
  else
    for (var i = 0; i < n; i++)
      console.log("");
  return;
}


/*********************
 * Exporting
 ********************/
module.exports = {
  border,
  space
}

