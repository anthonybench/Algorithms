//=============================================
//=============================================
// Binary Tree
// BST.js
// 
// Isaac Yep (SleepyBoy)
//=============================================
//=============================================

/*********************
 * BST Node
 ********************/
class Node {
    constructor(data) {
      this.data = data;
      this.left = null;
      this.right = null;
    }
  }

/*********************
 * BST Functionality
 ********************/
class BST {
  constructor(seed = null) {
    this.root = seed;
    if (seed) {
      this.height = this.getHeight(seed);
      this.size = this.getSize(seed);
    }
    else {
      this.height = 0;
      this.size = 0;
    }
  }

  /*
    > Insert new node with input data.
    > Comprised of wrapper that calls
      recursive worker.
    > Return (void).
  */
  add(data) {
    if (!this.root) {
      this.root = new Node(data);
      this.height++;
      this.size++;
      return;
    }

    this.addR(this.root, data, null, 0);
    this.height = this.getHeight(this.root);

    return;
  }
  addR(curr, data, prev, lr) {
    if (!curr) {
      this.size++;
      (lr == 0) ? (prev.left = new Node(data)) : (prev.right = new Node(data));
      return;
    }

    if (data >= curr.data)
      return this.addR(curr.right, data, curr, 1)
    return this.addR(curr.left, data, curr, 0)
  }

  /*
    > Remove node matching input data.
    > Comprised of wrapper that calls
      recursive worker.
    > Return (void).
  */
  remove(data) {
    if (!(this.root)) {
      console.log("Empty tree.");
      return;
    }

    let m1 = this.size;
    this.removeR(this.root, data);
    let m2 = this.size;
    if (m1 != m2)
      this.height = this.getHeight(this.root);
    else
      console.log(data, "could not be removed, not found.");

    return;
  }
  removeR(curr, data) {
    if (!curr)
      return null;

    if (data < curr.data)
      curr.left = this.removeR(curr.left, data);
    else if (data > curr.data)
      curr.right = this.removeR(curr.right, data);
    else {

      if (!(curr.left)) {
        let temp = curr.right;
        curr = null;
        this.size--;
        return temp;
      }
      if (!(curr.right)) {
        let temp = curr.left;
        curr = null;
        this.size--;
        return temp;
      }

      let marker = curr.right;
      while (marker.left)
        marker = marker.left;
      curr.data = marker.data;
      curr.right = this.removeR(curr.right, marker.data);
    }

    return curr;
  }

  /*
    > Log lowest common ancestor to console.
    > Comprised of wrapper that calls
      recursive worker.
    > Return lowest common ancestor (int).
  */
  lca(n1, n2) {
    if (!this.root)
      return null;

    let check1 = this.find(0, n1);
    let check2 = this.find(0, n2);
    if ((!check1) || (!check2)) {
      console.log("One of the numbers provided was not found.");
      return null;
    }

    return this.lcaR(n1, n2, this.root);
  }
  lcaR(n1, n2, curr) {
    if (!curr)
      return 0;

    let check1 = this.find(0, n1);
    let check2 = this.find(0, n2);
    if ((!check1) || (!check2))
      return 0;
    
    let diff1 = curr.data - n1;
    let diff2 = curr.data - n2;
    if ((diff1*diff2) <= 0) {
      console.log("LCA:", curr.data);
      return curr.data;
    }
    let res = 0;
    if ((diff1 < 0) && (diff2 < 0))
      res += this.lcaR(n1, n2, curr.right);
    else
      res += this.lcaR(n1, n2, curr.left);
    return res;
  }

  /*
    > Determine if input data exists in tree.
    > Comprised of wrapper that calls
      recursive worker.
    > First argument: 0 = no logging, 1 = logging.
    > Return search result (bool).
  */
  find(printing, data) {
    if (!this.root) {
      if (printing == 1)
        console.log("Empty tree.");
      return false;
    }

    return this.findR(printing, data, this.root);
  }
  findR(printing, data, curr) {
    if (!curr)
      return false;
    if (curr.data == data) {
      if (printing == 1)
        console.log(data, "is in the tree.");
      return true;
    }

    return (this.findR(printing, data, curr.left)) || (this.findR(printing, data, curr.right));
  }

  //remove leaves (wrapper)
  /*
    > Remove all leaves from tree.
    > Comprised of wrapper that calls
      recursive worker.
    > Return (void).
  */
  trim() {
    if (!this.root)
      console.log("Empty tree.");
    else if (this.size == 1) {
      this.root = null;
      this.size--;
      this.height--;
    }
    else {
      this.trimR(this.root, null, 0);
      this.height--;
      this.height = this.getHeight(this.root);
    }

    return;
  }
  trimR(curr, prev, lr) {
    if (!(curr.left) && !(curr.right)) {
      (lr == 0) ? (prev.left = null) : (prev.right = null);
      this.size--;
      return;
    }
    if (curr.left)
      this.trimR(curr.left, curr, 0);
    if (curr.right)
      this.trimR(curr.right, curr, 1);

    return;
  }

  /*
    > Clobber entire tree.
    > Return (void).
  */
  squash() {
    this.root = null;
    this.height = 0;
    this.size = 0;
    return;
  }

  /*
    > Convert tree to sorted array.
    > Comprised of wrapper that calls
      recursive worker.
    > Return sorted array ([Int]).
  */
  package() {
    let res = [];
    if (!this.root)
      return res;

    return this.packageR(this.root, res);
  }
  packageR(curr, res) {
    if (!curr)
      return res;

    this.packageR(curr.left, res);
    res.push(curr.data);
    this.packageR(curr.right, res);
    return res;
  }

  /*
    > Builds a balanced version of tree.
    > Uses utility to preprocess tree into sorted array.
    > Comprised of wrapper that calls
      recursive worker.
    > Return root node of balanced tree (Node).
  */
  balance() {
    if (!this.root)
      return null;
    let nums = this.package();
    return this.balanceR(nums);
  }
  balanceR(nums) {
    if (nums.length == 0)
      return null;

    let mid = ~~(nums.length / 2)
    let leftList = nums.slice(0, mid);
    let rightList = nums.slice(mid+1, nums.length);

    let node = new Node(nums[mid]);
    node.left = this.balanceR(leftList);
    node.right = this.balanceR(rightList);
    return node;
  }

  /*
    > Get smallest element in tree, can log to console.
    > Argument: 0 = no logging, 1 = logging.
    > Return smallest element (int).
  */
  getMin(printing) {
   if (!this.root) {
      if (printing == 1)
        console.log("Empty Tree.");
        return null;
    }
    else {
      let res = 0;
      let current = this.root;
      while (current.left)
        current = current.left;
      if (printing == 1)
        console.log("Min:    ", current.data);
      return current.data;
    }
  }

  /*
    > Get largest element in tree, can log to console.
    > Argument: 0 = no logging, 1 = logging.
    > Return largest element (int).
  */
  getMax(printing) {
    if (!this.root) {
      if(printing == 1)
        console.log("Empty tree. (null max)");
      return null;
    }
    else {
      let res = 0;
      let curr = this.root;
      while (curr.right)
        curr = curr.right;
      if (printing == 1)
        console.log("Max:    ", curr.data);
      return curr.data;
    }
  }

  /*
    > Get max height of tree.
    > Argument: Node of tree/subtree desired.
    > Utility intended for other methods.
    > Return max height (int).
  */
  getHeight(curr) {
    if (!curr)
      return 0;
    
    let hL = this.getHeight(curr.left);
    let hR = this.getHeight(curr.right);

    if (hL > hR)
      return (hL + 1);
    return hR + 1;
  }

  /*
  > Get size (population) of tree.
  > Argument: Node of tree/subtree desired.
  > Utility intended for other methods.
  > Return max height (int).
  */
  getSize(curr) {
    if (!curr)
      return 0;
    
    return 1 + this.getSize(curr.left) + this.getSize(curr.right);
  }

  /*
    > Log entire tree to console by
      element, each with it's level.
    > Comprised of wrapper that calls
      recursive worker.
    > Return (void).
  */
  display() {
    if (!this.root)
      console.log("Empty tree.");
    else {
      console.log("   Binary Tree Layout");
      return this.displayR(this.root, 1);
    }
    return;
  }
  displayR(curr, lvl) {
    if (!curr)
      return;

    console.log("Level", lvl, "==>   ", curr.data, " ");
    this.displayR(curr.left, lvl + 1);
    this.displayR(curr.right, lvl + 1);
    
    return;
  }

  /*
    > Log all information to the console.
    > Conglomerate of other methods.
    > Return (void).
  */
  diagnose() {
    console.log("-------------------------");
    this.display();
    console.log("-------------------------");
    console.log("Height: ", this.height);
    console.log("Size:   ", this.size);
    this.getMin(1);
    this.getMax(1);
    return;
  }

}


/*********************
 * Exporting
 ********************/
  module.exports = {
    Node,
    BST
  }
  