while (true)
{
    while (root != null)
    {
        stack.add(root);
        root = root.left;
    }
    root = stack.removeLast();
    if (--k == 0) return root.val;
    root = root.right;
}
