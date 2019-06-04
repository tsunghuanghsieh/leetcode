/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    var mapEmails = new Map();
    for (var i = 0; i < emails.length; i++) {
        var email = emails[i];
        var parts = email.split('@');
        var uid = parts[0];
        var dname = parts[1];

        // ignore everything after + in user id
        var idxPlus = uid.indexOf('+');
        if (idxPlus > 0) {
            uid = uid.substr(0, idxPlus);
        }
        // strip . (period) from user id
        uid = uid.replace(/\./g, '');

        mapEmails.set(uid + '@' + dname, '');
    }

    return mapEmails.size;
};