//=============================================
//=============================================
// Linear Linked List
// LLL.js
//=============================================
//=============================================
// LLL node
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

// Functionality
class LLL {
  constructor() {
    this.head = null;
  }

  //add new node
  add(data) {
    const newNode = new Node(data);
    
    if (!this.head)
      this.head = newNode;
    else {
      newNode.next = this.head;
      this.head = newNode;
    }
    return;
  }

  //remove last node
  clip() {
    let current = this.head;

    if (!this.head)
      console.log("Empty list.");
    else if (!this.head.next)
      this.head = null;
    else {
      while(current.next.next)
        current = current.next;
      current.next = null;
    }
    return;
  }

  //display entire list
  display() {
    let current = this.head;
    let res = "";

    if (!this.head)
      console.log("Emptly List");
    else {
      while (current) {
        let buff = (current.data).toString();
        res = res.concat(buff);
        res = res.concat(" --> ");
        current = current.next;
      }
      res = res.concat("NULL");
      console.log(res);
    }
    return;
  }

}

//exports enabled
module.exports = {
  Node,
  LLL
}

