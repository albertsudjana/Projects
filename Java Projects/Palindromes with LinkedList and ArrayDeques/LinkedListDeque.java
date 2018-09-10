public class LinkedListDeque<T> implements Deque<T> {
    private Node sentinel;
    private int size;


    public LinkedListDeque() {
        sentinel = new Node(null);
        sentinel.next = sentinel;
        sentinel.prev = sentinel;
        size = 0;
    }

    @Override
    public void addFirst(T item) {
        Node temp = new Node(item);
        if (size == 0) {
            sentinel.next = temp;
            sentinel.prev = temp;
            temp.next = sentinel;
            temp.prev = sentinel;
        } else {
            sentinel.next.prev = temp;
            temp.next = sentinel.next;
            temp.prev = sentinel;
            sentinel.next = temp;
        }
        size++;

    }

    @Override
    public void addLast(T item) {
        Node temp = new Node(item);
        if (size == 0) {
            sentinel.next = temp;
            sentinel.prev = temp;
            temp.next = sentinel;
            temp.prev = sentinel;
        } else {
            temp.next = sentinel;
            temp.prev = sentinel.prev;
            sentinel.prev.next = temp;
            sentinel.prev = temp;
        }
        size++;
    }

    @Override
    public boolean isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public void printDeque() {
        Node temp = sentinel.next;
        while (temp.next != sentinel) {
            System.out.print(temp.item);
            temp = temp.next;
        }
        System.out.print(temp.item);
        return;
    }

    @Override
    public T removeFirst() {
        if (size == 0) {
            return null;
        } else {
            size--;
            Node temp = sentinel.next;
            sentinel.next = sentinel.next.next;
            sentinel.next.prev = sentinel;
            return temp.item;
        }

    }

    @Override
    public T removeLast() {
        if (size == 0) {
            return null;
        } else {
            size--;
            Node temp = sentinel.prev;
            sentinel.prev = sentinel.prev.prev;
            sentinel.prev.next = sentinel;
            return temp.item;
        }
    }

    @Override
    public T get(int index) {
        Node temp = sentinel.next;
        while (index != 0) {
            temp = temp.next;
            index--;
        }
        return temp.item;
    }

    private T getRecursiveHelper(Node current, int index) {
        if (index == 0) {
            return current.item;
        } else {
            return getRecursiveHelper(current.next, index - 1);
        }
    }

    @Override
    public T getRecursive(int index) {
        return getRecursiveHelper(sentinel.next, index);
    }

    private class Node {
        Node prev;
        private T item;
        private Node next;

        Node(T val) {
            item = val;
        }

    }
}
