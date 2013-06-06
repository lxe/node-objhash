# node-objhash

Retrieve a v8 object [identity hash](http://izs.me/v8-docs/classv8_1_1Object.html#a5309f7a349feb906a05ee45b6feeaab1).

## Usage

```javascript
var objhash = require('objhash');

var o = { foo : 'bar' };
  , ref = o;

console.log(objhash(o));                // Returns a 32 bit identity hash
console.log(objhash(ref));              // Returns the same identity hash
console.log(objhash({ foo : 'bar' }));  // Returns a different identity hash

console.log(objhash('A String')); // Returns 'A String'

console.log(objhash(42));         // Returns 42
```

## License

MIT