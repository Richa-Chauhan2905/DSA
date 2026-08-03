// export default function linear_search(array: number[], target: number): boolean {
//     for(let i = 0; i < array.length; i++){
//         if(array[i] === target) return true;
//     }
//     return false;
// }

// const array = [1, 2, 3, 4, 5];
// console.log(linear_search(array, 3));

// export default function binary_search(array: number[], target: number): boolean {
//     let low = 0
//     let high = array.length - 1

//     do{
//         const mid = Math.floor(low + (high - low) / 2)
//         const value = array[mid]
//         if(value === target) return true
//         else if(value > target){
//             high = mid;
//         }
//         else{
//             low = mid + 1;
//         }
//     } while (low < high)

//     return false
// }

// export default function bubble_sort(arr: number[]): number[] {
//   for (let i = 0; i < arr.length; i++) {
//     for (let j = 0; j < arr.length - 1 - i; j++) {
//       if (arr[j] > arr[j + 1]) {
  //         const temp = arr[j];
  //         arr[j] = arr[j + 1];
  //         arr[j + 1] = temp;
  //       }
  //     }
  //   }
  
  //   return arr;
  // }

  // const array = [5, 3, 8, 1, 2];
  // console.log(bubble_sort(array));

  type QNode<T> = {
  value: T;
  next?: QNode<T>;
};

export default class Queue<T> {
  public length: number;
  private head?: QNode<T>;
  private tail?: QNode<T>;

  constructor() {
    this.head = this.tail = undefined;
    this.length = 0;
  }

  enqueue(item: T) {
    const node = { value: item } as QNode<T>;
    this.length++;
    if (!this.tail) {
      this.tail = this.head = { value: item } as QNode<T>;
    }

    this.tail.next = node;
    this.tail = node;
  }
  deque(): T | undefined {
    if (!this.head) {
      return undefined;
    }

    this.length--;
    const head = this.head;
    this.head = this.head.next;

    head.next = undefined;

    return head.value;
  }
  peek(): T | undefined {
    return this.head?.value;
  }

  display(): void {
    let current = this.head;
    const values: T[] = [];

    while (current) {
      values.push(current.value);
      current = current.next;
    }

    console.log(values);
  }
}

const queue = new Queue<number>();

queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

queue.display();

console.log("Removed:", queue.deque());

queue.display();

console.log("Removed:", queue.deque());

queue.display();
