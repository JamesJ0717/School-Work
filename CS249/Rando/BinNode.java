public class BinNode <E extends Comparable<E>> implements Comparable<BinNode<E>> {
    private E data;
    private BinNode<E> left = null;
    private BinNode<E> right = null;

    public BinNode(){
        this.data = data;
    }
    public BinNode<E> getLeft()
    {
        return left;
    }
    public BinNode<E> getRight()
    {
        return right;
    }
    public void setLeft(BinNode<E> node)
    {
        left = node;
    }
    public void setRight(BinNode<E> node)
    {
        right = node;
    }

    public int compareTo(BinNode<E> node)
    {
        return data.compareTo(node.data);
    }
    public String toString() 
    {
        return "{" + data.toString() + "}";
    }
}