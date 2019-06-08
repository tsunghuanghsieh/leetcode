var lru = new Map();
// key: key of key/value pair from input
// value: index of key stored in array
var mapOrder = new Map();
// index: from least recently used to most recently used
// value: key of key/value pair from input
var arrOrder = [];
var max = 0;

/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
    lru = new Map();
    mapOrder = new Map();
    arrOrder = [];
    max = capacity;
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (lru.has(key)) {
        updateLRUList(key);
        return lru.get(key);
    }
    return -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (mapOrder.has(key) || arrOrder.length >= max) {
        var evictedKey = updateLRUList(key);
        lru.delete(evictedKey);
    } else {
        mapOrder.set(key, arrOrder.length);
        arrOrder.push(key);
    }
    lru.set(key, value);
};

//
// @param {number} key
// It finds and updates recent used lists for all keys.
// If the key is not found, it does nothing.
//
function updateLRUList(key) {
    // initialize for capacity is reached
    // regardless if key already exists
    var position = 0;
    var deleteKey = arrOrder[0];
    if (mapOrder.has(key)) {
        // overwrite initialization values
        position = mapOrder.get(key);
        deleteKey = arrOrder[position];
    }
    for (var idx = position; idx < arrOrder.length - 1; idx++) {
        arrOrder[idx] = arrOrder[idx + 1];
        mapOrder.set(arrOrder[idx + 1], idx);
    }
    mapOrder.delete(deleteKey);
    mapOrder.set(key, arrOrder.length - 1);
    arrOrder[arrOrder.length - 1] = key;
    return deleteKey;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */