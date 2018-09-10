public class ArrayDeque<T> {

    private T[] items;
    private int nextFirst;
    private int nextLast;
    private int size;
    private int capacity;


    public ArrayDeque() {
        items = (T[]) new Object[8];
        size = 0;
        nextFirst = 4;
        nextLast = 5;
        capacity = 8;
    }

    private void resize(int newCapacity, String choice) {
        T[] temp = (T[]) new Object[newCapacity];
        int tempNextFirst = nextFirst;
        int tempNextLast = nextLast;
        if (nextLast >= this.capacity - 1) {
            tempNextLast = 0;
        }
        if (choice.equals("Increase")) {
            System.arraycopy(items, tempNextFirst + 1, temp,
                    newCapacity - (size - (nextFirst + 1)), size - (nextFirst + 1));
            if (tempNextLast == 0 && ((size - (nextFirst + 1)) != size)) {
                tempNextLast = this.capacity - 1;
            }
            System.arraycopy(items, 0, temp, 0, tempNextLast);
            nextFirst = newCapacity - size + (nextFirst);
        }
        if (choice.equals("Decrease")) {
            System.arraycopy(items, tempNextFirst + 1, temp,
                    newCapacity - this.capacity + (nextFirst + 1), this.capacity - (nextFirst + 1));
            System.arraycopy(items, 0, temp, 0, tempNextLast);
            nextFirst = newCapacity - (this.capacity - (nextFirst));
            if (tempNextLast == 0) {
                tempNextLast = newCapacity - 1;
            }
        }
        nextLast = tempNextLast;
        this.capacity = newCapacity;
        items = temp;
    }


    public void addFirst(T item) {
        if (arrayFull()) {
            resize(capacity * 2, "Increase");
        }
        if (nextFirst < 0) {
            nextFirst = capacity - 1;
        }
        items[nextFirst] = item;
        nextFirst -= 1;
        size += 1;
    }

    private boolean arrayFull() {
        if (size == capacity) {
            return true;
        }
        return false;
    }

    public void addLast(T item) {
        if (arrayFull()) {
            resize(capacity * 2, "Increase");
        }
        if (nextLast == capacity) {
            nextLast = 0;
        }
        items[nextLast] = item;
        nextLast += 1;
        size += 1;
    }

    public boolean isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    public int size() {
        return size;
    }

    public void printDeque() {
        int tempIndex = nextFirst + 1;
        for (int i = 0; i < size; i++) {
            if (tempIndex >= capacity) {
                tempIndex = 0;
            }
            System.out.print(items[tempIndex]);
            tempIndex += 1;
        }
    }

    public T removeFirst() {
        if (size <= 0) {
            return null;
        }
        if (nextFirst >= this.capacity - 1) {
            nextFirst = -1;
        }
        nextFirst += 1;
        T temp = items[nextFirst];
        items[nextFirst] = null;
        size -= 1;
        usageOptimized();
        return temp;

    }

    public T removeLast() {
        if (size <= 0) {
            return null;
        }
        if (nextLast == 0) {
            nextLast = this.capacity;
        }
        nextLast -= 1;
        T temp = items[nextLast];
        items[nextLast] = null;
        size -= 1;
        usageOptimized();
        return temp;

    }

    private void usageOptimized() {
        if ((size < capacity / 2) && capacity >= 16) {
            resize(capacity / 2, "Decrease");
        }
    }

    public T get(int index) {
        if (index >= size) {
            return null;
        }
        int tempIndex = nextFirst + 1 + index;
        if (tempIndex >= capacity) {
            tempIndex -= capacity;
        }
        return items[tempIndex];
    }
}
