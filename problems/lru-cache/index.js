/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.lru = new Map();
    // key: key of key/value pair from input
    // value: index of key stored in array
    this.mapOrder = new Map();
    // index: from least recently used to most recently used
    // value: key of key/value pair from input
    this.arrOrder = new Array();
    this.max = capacity;

    //
    // @param {number} key
    // It finds and updates recent used lists for all keys.
    // If the key is not found, it does nothing.
    //
    this.updateLRUList = function(key) {
        // initialize for capacity is reached
        // regardless if key already exists
        var position = 0;
        var deleteKey = this.arrOrder[0];
        if (this.mapOrder.has(key)) {
            // overwrite initialization values
            position = this.mapOrder.get(key);
            deleteKey = this.arrOrder[position];
        }
        for (var idx = position; idx < this.arrOrder.length - 1; idx++) {
            this.arrOrder[idx] = this.arrOrder[idx + 1];
            this.mapOrder.set(this.arrOrder[idx + 1], idx);
        }
        this.mapOrder.delete(deleteKey);
        this.mapOrder.set(key, this.arrOrder.length - 1);
        this.arrOrder[this.arrOrder.length - 1] = key;
        return deleteKey;
    }
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.lru.has(key)) {
        this.updateLRUList(key);
        return this.lru.get(key);
    }
    return -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (this.mapOrder.has(key) || this.arrOrder.length >= this.max) {
        var evictedKey = this.updateLRUList(key);
        this.lru.delete(evictedKey);
    } else {
        this.mapOrder.set(key, this.arrOrder.length);
        this.arrOrder.push(key);
        for (var idx = 0; idx < this.arrOrder.length; idx++) {
            console.log("this.arrOrder[idx] " + this.arrOrder[idx]);
        }
    }
    this.lru.set(key, value);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */