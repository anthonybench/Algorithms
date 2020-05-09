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
    this.tail = null;
  }
}

// Functionality
class LLL {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  //add new node
  add(data) {
    const newNode = new Node(data);
    
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
    }
    else {
      newNode.next = this.head;
      this.head = newNode;
      let marker = this.head;
      while (marker.next)
        marker = marker.next;
      this.tail = marker;
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
      this.tail = current;
    }
    return;
  }

  //reverse list (wrapper)
  reverse() {
    let temp = this.head;
    this.reverseW(this.head);
    this.tail = temp;
    
    return;
  }
  //reverse list (work)
  reverseW(curr) {
    if (!curr)
      return null;
    if (!curr.next) {
      this.head = curr;
      return curr;
    }
    let temp = this.reverseW(curr.next);
    temp.next = curr;
    curr.next = null;
    return curr;
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

  //display head
  peekHead() {
    console.log("Head: ", this.head.data);
    return;
  }

  //display tail
  peekTail() {
    console.log("Tail: ", this.tail.data);
  }

}

//exports enabled
module.exports = {
  Node,
  LLL
}

