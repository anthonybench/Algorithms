//=============================================
//=============================================
// Linear Linked List
// LLL.js
//
// Isaac Yep (SleepyBoy)
//=============================================
//=============================================

/*********************
 * LLL Node
 ********************/
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

/*********************
 * LLL Functionality
 ********************/
class LLL {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  /*
    > Insert new node with input data.
    > Return (void).
  */
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
    this.length += 1;
    return;
  }

  /*
    > Delete last node of list.
    > Return (void).
  */
  clip() {
    let current = this.head;

    if (!this.head)
      console.log("Empty list.");
    else if (!this.head.next) {
      this.head = null;
      this.length--;
    }
    else {
      while(current.next.next)
        current = current.next;
      current.next = null;
      this.tail = current;
      this.length--;
    }
    return;
  }

  /*
    > Delete first node to match input data.
    > Return (void).
  */
  remove(num) {
    if (!this.head)
      console.log("Empty list.");
    else if (this.head.data == num) {
      if (!(this.head.next))
        this.tail = null;
      this.head = this.head.next;
      this.length--;
    }
    else {
      let curr = this.head;
      let prev = null;
      while (curr) {
        if (curr.data == num) {
          prev.next = curr.next;
          if (!curr.next)
            this.tail = prev;
          this.length--;
          return;
        }
        prev = curr;
        curr = curr.next;
      }
      console.log("Removal failed: data not found.");
    }
    return;
  }

  /*
    > Clobber entire list.
    > Return (void).
  */
  squash() {
    while(this.head)
      this.clip();
    this.head = null;
    this.tail = null;
    this.length = 0;

    return;
  }

  /*
    > Obtain minimum value within list.
    > Return minimal value (Int).
  */
  getMin() {
    let min = this.head.data;
    let curr = this.head;

    while (curr) {
      if (curr.data < min)
        min = curr.data;
      curr = curr.next;
    }
    
    return min;
  }

  /*
    > Obtain maximum value within list.
    > Return maximal value (Int).
  */
  getMax() {
    let max = this.head.data;
    let curr = this.head;

    while (curr) {
      if (curr.data > max)
        max = curr.data;
      curr = curr.next;
    }
    
    return max;
  }

  /*
    > Sort list in ascending order.
    > Return (void).
  */
  sort() {
    if (!this.head)
      console.log("Empty list.");
    else if (!this.head.next)
      console.log("List only has one element.");
    else {
      let resPack = [];
      let sz = this.length;
      while (this.length > 0) {
        let min = this.getMin();
        resPack.unshift(min);
        this.remove(min);
      }
      for (var i = 0; i < sz; i++)
        this.add(resPack[i]);
    }

    return;
  }

  /*
    > Reverse order of list.
    > Comprised of wrapper that calls
      recursive worker.
    > Return (void).
  */
  reverse() {
    if (!this.head)
      console.log("Empty List.");
    else if (this.length == 1)
      console.log("List only has one element.");
    else {
      let temp = this.head;
      this.reverseW(this.head);
      this.tail = temp;
    }
    
    return;
  }
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

  /*
    > Log entire list to console.
    > Return (void).
  */
  display() {
    let current = this.head;
    let res = "";

    if (!this.head)
      console.log("Empty List.");
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

  /*
    > Log all information to the console.
    > Return (void).
  */
  diagnose() {
    if (!this.head)
      console.log("Empty List.");
    else {
      this.display();
      console.log("Size: ", this.length);
      console.log("Head: ", this.head.data);
      console.log("Tail: ", this.tail.data);
    }

    return;
  }

}

/*********************
 * Exporting
 ********************/
module.exports = {
  Node,
  LLL
}

