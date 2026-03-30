class MyHashMap {
    private Node[] buckets;
    private int size = 1000;

    class Node {
        int key;
        int value;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public MyHashMap() {
        this.buckets = new Node[size];  
    }

    private int hash(int key) {
        return key % size;
    }
    
    public void put(int key, int value) {
        int index = hash(key);
        Node head = buckets[index];
        Node curr = head;

        while(curr != null) {
            if(curr.key == key) {
                curr.value = value;
                return;
            }
            curr = curr.next;
        }

        Node newNode = new Node(key, value);
        newNode.next = head;
        buckets[index] = newNode; 
    }
    
    public int get(int key) {
        int index = hash(key);
        Node head = buckets[index];
        Node curr = head;

        while(curr != null) {
            if(curr.key == key) {
                return curr.value;
            }
            curr = curr.next;
        } 
        return -1;
    }
    
    public void remove(int key) {
        int index = hash(key);
        Node head = buckets[index];
        Node curr = head;
        Node prev = null;

        while(curr != null) {
            if(curr.key == key) {
                if(prev == null) {
                    buckets[index] = curr.next;
                } else {
                    prev.next = curr.next;
                }
            }
            prev = curr;
            curr = curr.next;
        } 
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */