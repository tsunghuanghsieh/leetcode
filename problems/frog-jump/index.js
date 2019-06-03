/**
 * @param {number[]} stones
 * @return {boolean}
 */
var canCross = function(stones) {
    var result = false;
    var lastStone = stones[stones.length - 1];

    if (stones[1] != 1) return result;

    var mapStones = new Map();
    for (var i = 1; i < stones.length; i++) {
        mapStones.set(stones[i], new Set());
    }

    // var queue = [];
    // key: position
    // value: k
    // var start = new Jump(0, 1);
    var landings = [];
    var distances = [];
    landings.push(0);
    distances.push(1);
    // queue.push(start);
    // while (queue.length > 0) {
    while (landings.length > 0) {
        // console.log("index " + mapStones.get(key) + " position " + key);
        // var current = queue.shift();
        // var next;
        // var k = current.k;
        // var position = current.position;
        var k = distances.shift();
        var position = landings.shift();
        // console.log("working on [" + position + "," + k + "]");
        for (var i = k - 1; i < k + 2; i++) {
            if (i <= 0) continue;

            if (mapStones.has(position + i)) {
                // if (!mapStonesKeys.has(position + i + '_' + i)) {
                //     mapStonesKeys.set(position + i + '_' + i, 1);
                    // queue.push(next);
                if (!mapStones.get(position + i).has(i)) {
                    mapStones.get(position + i).add(i);
                    landings.push((position + i));
                    distances.push(i);
                }
                if (position + i == lastStone) result = true;
            }
        }
    }

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