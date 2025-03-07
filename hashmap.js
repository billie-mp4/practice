class HashMap{
    capacity=0
    load_factor=1
    buckets={}
    constructor(){
        this.capacity=0
        this.load_factor=.75
    }
    hash(key){
        let hashCode
        for(let i=0;i<key.length;i++){
            hashCode=(31*hashCode+key.charCodeAt(i))%16
        }
        return hashCode
    }
    set(key,value){
        this[key]=value
        if(this.capacity*this.load_factor==16)capacity*=2
        this.buckets[this.hash(key)]=key
        this.capacity++
    }
    get(key){
        if(this.contains(key))
            return this[key]
        return null
    }
    has(key){
        if(this.buckets[this.hash(key)]==key)
            return true
        return false
    }
    remove(key){
        if(this.buckets[this.hash(key)]==key){
            this[key]=null
            this.capacity--
            return true
        }
        return false
    }
    length(){
        return this.capacity
    }
    clear(){
        this.keys.foreach(key,()=>{
            this.remove(key)
        })
    }
    getKeys(){
        let arr,i=0
        this.keys.foreach(key,()=>{
            arr[i]=key
            i++
        })
        return arr
    }
    values(){
        let arr,i=0
        this.keys.foreach(key,()=>{
            arr[i]=this.keys[key]
            i++
        })
        return arr
    }
    entries(){
        let arr,i=0
        this.keys.foreach(key,()=>{
            arr[i]=[key,this.keys[key]]
            i++
        })
        return arr
    }
}
const test=new HashMap()
test.set('apple', 'red')
test.set('banana', 'yellow')
test.set('carrot', 'orange')
test.set('dog', 'brown')
test.set('elephant', 'gray')
test.set('frog', 'green')
test.set('grape', 'purple')
test.set('hat', 'black')
test.set('ice_cream', 'white')
test.set('jacket', 'blue')
test.set('kite', 'pink')
test.set('lion', 'golden')
console.log(test.getKeys())