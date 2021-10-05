// https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/  

// from leaf to leaf

//         10
//         / \
//        2    10
//       /  \    \
//     20    1   -25
//               /  \
//              3    4

// Output = 20 + 2 + 1 = 23  (Coz other side will give net -1 or -2 result)

// temp <- max(20, 9) + value of parent node  // makes sense
// temp <- max(-40, -10) + value of parent node // If parent node is a leaf node then we take value of this node only, if it is not then we have to move further and take -ve values in addition
// ans <- l + r + val of parent node

// code
int solve(Node * root, int& res){
    // BASE CONDITION
    if(root == nullptr){
        return 0;
    }

    // HYPOTHESIS
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    // INDUCTION
    int temp = max(l, r) + root->value;
    // we can or cannot write below line coz if its leaf node then uske subtree se -ve value ayegi hi ni qki subtree hi nahi hai XD
    if(root->left == nullptr && root->right == nullptr){  // when it is a leaf node
        temp = max(temp, root-> value); // chose bw temp value and node value
    }
    int ans = max(temp, l + r + root->value);
    int res = max(res, ans);

    return temp;
}

int main(){
    int res = INT_MIN;
    solve(root, res);

    return res;
}



