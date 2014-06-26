var assert = require('assert');
var objhash = require('..')

describe('objhash', function () {

  function verifyIdentity (hash) {
    assert.ok(hash);
    assert.ok(!isNaN(hash));
    assert.ok(hash > 0);
  }

  it('should return an identity hash of a simple object', function () {
    verifyIdentity(objhash({ foo : 'bar' }));
  });

  it('should return an identity hash of a native node object', function () {
    verifyIdentity(objhash(process));
  });

  it('should return the same hash for the same object reference', function () {
    var o1 = { foo : 'bar' };
    var o2 = o1;
    var hash1 = objhash(o1);
    var hash2 = objhash(o2);
    verifyIdentity(hash1);
    verifyIdentity(hash2);
    assert(hash1 === hash2);
  });

  it('should (hopefully) return 2 different hashes for different references', function () {
    var o1 = { foo : 'bar' };
    var o2 = { zoo : 'zar' };
    var hash1 = objhash(o1);
    var hash2 = objhash(o2);
    verifyIdentity(hash1);
    verifyIdentity(hash2);
    assert(hash1 !== hash2);
  });

  it('should return the same primitive passed into it', function () {
    var primitives = ['a string', 42, null, undefined, true];
    primitives.forEach(function (primitive) {
      var hash = objhash(primitive);
      assert(primitive === hash);
    });
  });
});
