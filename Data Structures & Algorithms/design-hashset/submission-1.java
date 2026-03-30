class MyHashSet {
    private Node[] buckets;
    private int size = 1000;

    class Node {
        int key;
        Node next;

        Node(int key) {
            this.key = key;
            this.next = null;
        }
    }

    public MyHashSet() {
        this.buckets = new Node[size];  
    }

    private int hash(int key) {
        return key % size;
    }
    
    public void add(int key) {
        int index = hash(key);
        Node head = buckets[index];
        Node temp = head;

        while(temp != null) {
            if(temp.key == key) {
                return;
            }
            temp = temp.next;
        }

        Node newNode = new Node(key);
        newNode.next = head;
        buckets[index] = newNode;  
    }
    
    public void remove(int key) {
        int index = hash(key);
        Node curr = buckets[index];
        Node prev = null;

        while(curr != null) {
            if(curr.key == key) {
                if(prev == null) {
                    buckets[index] = curr.next;
                } else {
                    prev.next = curr.next;
                }
                return;
            }
            prev = curr;
            curr = curr.next;
        }  
    }
    
    public boolean contains(int key) {
        int index = hash(key);
        Node curr = buckets[index];

        while(curr != null) {
            if(curr.key == key) {
                return true;
            }
            curr = curr.next;
        }
        return false;  
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */