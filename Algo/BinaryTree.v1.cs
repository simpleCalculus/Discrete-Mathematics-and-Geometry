    public class BinTreeSearch<T> where T : IComparable<T>
    {
        BinTreeSearch<T> parent, left, right;
        T val;
        public BinTreeSearch(T val, BinTreeSearch<T> parent)
        {
            ++Count;
            this.val = val;
            this.parent = parent;
        }

        public int Count { get; private set; }

        public void Add(T val)
        {
            if (val.CompareTo(this.val) < 0)
            {
                if (left == null)
                    left = new BinTreeSearch<T>(val, this);
                else
                    left.Add(val);
            }
            else
            {
                if (right == null)
                    right = new BinTreeSearch<T>(val, this);
                else right.Add(val);
            }
            ++Count;
        }

        private BinTreeSearch<T> _search(BinTreeSearch<T> tree, T val)
        {
            if (tree == null) return null;
            switch (val.CompareTo(tree.val))
            {
                case 1:
                    return _search(tree.right, val);
                case -1:
                    return _search(tree.left, val);
                case 0:
                    return tree;
                default:
                    return null;
            }
        }

        public BinTreeSearch<T> Search(T val)
        {
            return _search(this, val);
        }

        public bool Remove(T val)
        {
            BinTreeSearch<T> tree = Search(val);
            //Проверяем, существует ли данный узел
            if (tree == null)
            {
                //Узла не существует
                return false;
            }

            BinTreeSearch<T> curTree;

            //Case 0 Если удаляемый узел это лист
            if (Count > 1 && tree.right == null && tree.left == null)
            {
                if (tree == tree.parent.right)
                    tree.parent.right = null;
                else
                    tree.parent.left = null;
                tree.parent = null;
            }
            else if (Count == 1)
            {
                tree = null;
                --Count;
                return true;
            }

            //Case 1 У удаляемого узла нет правого ребенка.
            //В этом случае мы просто перемещаем левого ребенка (при его наличии) на место удаляемого узла.
            if (tree.right == null && tree.left != null)
            {
                curTree = tree.left;
                tree.val = curTree.val;
                tree.left = curTree.left;
                tree.right = curTree.right;
                if (curTree.left != null)
                    curTree.left.parent = tree;
                if (curTree.right != null)
                    curTree.right.parent = tree;
                curTree.parent = null;
                curTree.right = null;
                curTree.left = null;
            }

            //Case 2 У удаляемого узла есть правый ребенок, у которого, в свою очередь нет левого ребенка.
            //В этом случае нам надо переместить правого ребенка удаляемого узла на его место.
            if (tree.right != null && tree.right.left == null)
            {
                curTree = tree.right;
                tree.val = curTree.val;
                tree.right = curTree.right;
                if (tree.right != null)
                    tree.right.parent = tree;
                curTree.right = null;
                curTree.parent = null;
            }

            //Case 3 У удаляемого узла есть первый ребенок, у которого есть левый ребенок.
            //В этом случае место удаляемого узла занимает крайний левый ребенок правого ребенка удаляемого узла.
            if (tree.right != null && tree.right.left != null)
            {
                curTree = tree.right;
                while (curTree.left != null)
                {
                    curTree = curTree.left;
                }
                tree.val = curTree.val;
                if (curTree.right != null)
                {
                    curTree.val = curTree.right.val;
                    curTree.right.parent = null;
                    curTree.parent.left = null;
                }
                else
                {
                    curTree.parent.left = null;
                }
                curTree.parent = null;
            }
            --Count;
            return true;
        }

        private void _print(BinTreeSearch<T> node)
        {
            if (node.left != null)
                _print(node.left);
            Console.Write(node + " ");
            if (node.right != null)
                _print(node.right);
        }

        public void Print()
        {
            _print(this);
            Console.WriteLine();
        }

        public override string ToString()
        {
            return val.ToString();
        }
    }
