# node-objhash

Retrieve a node.js object's v8 [identity hash](http://izs.me/v8-docs/classv8_1_1Object.html#a5309f7a349feb906a05ee45b6feeaab1). 
This value can be used as a hasher to a memoization function drastically improving performance. 

The V8 Identity hash is *not guaranteed to be unique*, so make sure to watch out for collisions if you're using it as a hash map key.

## Usage

```javascript
var objhash = require('objhash');

var o = { 
  foo: 'bar' 
};

var ref = o;

// Returns a 32 bit identity hash
console.log(objhash(o)); 
// > 1023577207

// Returns the same identity hash, 
// as 'ref' is just a reference pointing to 'o'
console.log(objhash(ref));              
// > 1023577207

// Returns a different identity hash, as we are
// instantiating a different object.
// 
// Note that this behavior differs if you use JSON.stringify()
// as your memoize hasher
console.log(objhash({ foo : 'bar' }));  
// > 248433069

// For primitives, the function just returns the 
// value of the argument
console.log(objhash('A String')); 
// > 'A String'
console.log(objhash(42));
// > 42
```

## License

Copyright (c) 2014 Aleksey Smolenchuk

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
