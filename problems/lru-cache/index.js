/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.lru = new Map();
    this.max = capacity;
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.lru.has(key)) {
        var value = this.lru.get(key);
        this.lru.delete(key);
        this.lru.set(key, value);
        return value;
    }
    return -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (this.lru.has(key)) {
        this.lru.delete(key);
    } else if (this.lru.size == this.max) {
        this.lru.delete(this.lru.keys().next().value);
    }
    this.lru.set(key, value);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */