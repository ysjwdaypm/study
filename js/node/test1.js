// hello.js

/**

node-gyp configure
node-gyp build
*/

const addon = require('./build/Release/addon');

console.log(addon.hello()); // 'world'