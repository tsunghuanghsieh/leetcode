/**
 * @param {number[]} stones
 * @return {boolean}
 */
var canCross = function(stones) {
    var result = false;
    var size = 0;
    var lastStone = stones[stones.length - 1];

    if (stones == null || stones.length == 0) return result;
    if (stones[1] != 1) return result;

    var mapStones = new Map();
    var mapStonesKeys = new Map();
    for (var i = 1; i < stones.length; i++) {
        mapStones.set(stones[i], i);
    }

    var queue = [];
    // key: position
    // value: k
    var start = new Jump(0, 1);
    queue.push(start);
    mapStones.forEach((value, key) => {
        // console.log("index " + mapStones.get(key) + " position " + key);
        size = queue.length;
        if (size == 0) return result;
        for (var s = 0; s < size; s++) {
            var current = queue.shift();
            var next;
            var k = current.k;
            var position = current.position;
            // console.log("working on [" + position + "," + k + "]");
            // k - 1
            // console.log("position " + position + " step " + (k - 1) + " (" + k + " - 1): expected " + (position + k - 1));
            if (k - 1 > 0 && mapStones.has(position + k - 1)) {
                next = new Jump((position + k - 1), (k - 1));
                // console.log("[" + position + "," + k + "] " + "pushing (k - 1) [" + (position + k - 1) + "," + (k - 1) + "]")
                // console.log(position + k - 1 + '_' + (k - 1));
                if (!mapStonesKeys.has(position + k - 1 + '_' + (k - 1))) {
                    mapStonesKeys.set(position + k - 1 + '_' + (k - 1), 1);
                    queue.push(next);
                }
                if (position + k - 1 == lastStone) result = true;
            }
            // k
            // console.log("position " + position + " step " + k + " (" + k + "): expected " + (position + k));
            if (mapStones.has(position + k)) {
                next = new Jump((position + k), k);
                // console.log("[" + position + "," + k + "] " + "pushing (k) [" + (position + k) + "," + (k) + "]")
                // console.log(position + k + '_' + k);
                if (!mapStonesKeys.has(position + k + '_' + k)) {
                    mapStonesKeys.set(position + k + '_' + k, 1);
                    queue.push(next);
                }
                if (position + k == lastStone) result = true;
            }
            // k + 1
            // console.log("position " + position + " step " + (k + 1) + " (" + k + " + 1): expected " + (position + k + 1));
            if (mapStones.has(position + k + 1)) {
                next = new Jump((position + k + 1), (k + 1));
                // console.log("[" + position + "," + k + "] " + "pushing (k + 1) [" + (position + k + 1) + "," + (k + 1) + "]")
                // console.log(position + k + 1 + '_' + (k + 1));
                if (!mapStonesKeys.has(position + k + 1 + '_' + (k + 1))) {
                    mapStonesKeys.set(position + k + 1 + '_' + (k + 1), 1);
                    queue.push(next);
                }
                if (position + k + 1 == lastStone) result = true;
            }
        }
    });

    return result;
};

class Jump {
    position;
    k;
    constructor (position, k) {
        this.position = position;
        this.k = k;
    }

    get position() {
        return this.position;
    }

    get k() {
        return this.k;
    }
}