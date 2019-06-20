/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
    var mapWords = new Map();
    var queue = new Array();
    var notFound = true;
    var count = 1;
    for (var idx = 0; idx < wordList.length; idx++) {
        if (diffWords(beginWord, wordList[idx])) {
            queue.push(wordList[idx]);
        } else {
            mapWords.set(wordList[idx], idx);
        }
        if (endWord == wordList[idx]) notFound = false;
    }
    // endWord not in the array
    if (notFound) return 0;
    while (queue.length > 0) {
        var roundLength = queue.length;
        count++;
        var tempQueue = queue; // use a temp queue so that we don't have to use shift().
        queue = [];
        for (var i = 0; i < roundLength; i++) {
            var word = tempQueue.pop();
            if (word == endWord) return count;
            for (const [key, value] of mapWords) {
                if (diffWords(word, key)) {
                    queue.push(key);
                    mapWords.delete(key);
                }
            }
        }
    }
    // no transformation leading to endWord
    return 0;
};

// @param {string} word1
// @param {string} word2
// @return {bool}
function diffWords(word1, word2) {
    var diffCnt = 0;
    for (var i = 0; i < word1.length; i++) {
        if (word1[i] != word2[i]) {
            diffCnt++;
        }
        // different by more than 1 character
        if (diffCnt > 1) return false;
    }
    return true;
}