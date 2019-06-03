/**
 * @param {number[]} stones
 * @return {boolean}
 */
var canCross = function(stones) {
    var result = false;
    var lastStone = stones[stones.length - 1];

    if (stones[1] != 1) {
        return result;
    } else {
        if (stones.length == 2) return true;
    }

    var mapStones = new Map();
    for (var i = 1; i < stones.length; i++) {
        mapStones.set(stones[i], new Set());
    }

    var landings = [1];
    var distances = [1];
    while (landings.length > 0) {
        var k = distances.shift();
        var position = landings.shift();
        for (var i = k - 1; i < k + 2; i++) {
            if (i <= 0) continue;

            if (mapStones.has(position + i)) {
                if (!mapStones.get(position + i).has(i)) {
                    mapStones.get(position + i).add(i);
                    landings.push((position + i));
                    distances.push(i);
                }
                if (position + i == lastStone) return true;
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