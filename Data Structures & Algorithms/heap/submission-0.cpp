class MinHeap {
private:
    vector<int> arr;

    void bubbleUp(int index) {
        while(index > 0) {
            int parent = (index - 1) / 2;

            if(arr[parent] <= arr[index]) {
                break;
            }

            if(index > 0) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
        }
    }

    void bubbleDown(int index) {
        int n = arr.size();

        while(true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if(left < n && arr[smallest] > arr[left]) {
                smallest = left;
            }

            if(right < n && arr[smallest] > arr[right]) {
                smallest = right;
            }

            if(smallest == index) {
                break;
            }

            swap(arr[index], arr[smallest]);
            index = smallest;
        }
    }
public:
    MinHeap() { }

    void push(int val) {
        arr.push_back(val);
        bubbleUp(arr.size() - 1);
    }

    int pop() {
        if(arr.empty()) return -1;
        
        int result = arr[0];
        arr[0] = arr.back();
        arr.pop_back();

        if(!arr.empty()) bubbleDown(0);
        return result;
    }

    int top() {
        return arr.empty() ? -1 : arr[0];
    }

    void heapify(const vector<int>& nums) {
        arr = nums;
        
        for(int i = (arr.size() / 2) - 1; i >= 0; i--) {
            bubbleDown(i);
        }
    }
};
