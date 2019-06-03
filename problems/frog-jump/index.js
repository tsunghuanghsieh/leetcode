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
        // special case: [0,1]
        if (stones.length == 2) return true;
    }

    var mapStones = new Map();
    for (var i = 1; i < stones.length; i++) {
        // set map key to position of stone and value to a set of jump distance
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
                // keep track of jump distance seen for given position
                // so that we don't duplicate the effort for the given position
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

// Jump clss is no longer needed
// Keeping it for javascript class reference
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