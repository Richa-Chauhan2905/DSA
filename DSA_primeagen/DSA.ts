// export default function linear_search(array: number[], target: number): boolean {
//     for(let i = 0; i < array.length; i++){
//         if(array[i] === target) return true;
//     }
//     return false;
// }

// const array = [1, 2, 3, 4, 5];
// console.log(linear_search(array, 3));

export default function binary_search(array: number[], target: number): boolean {
    let low = 0
    let high = array.length - 1

    do{
        const mid = Math.floor(low + (high - low) / 2)
        const value = array[mid]
        if(value === target) return true
        else if(value > target){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    } while (low < high)

    return false
}

const array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(binary_search(array, 31));