'use strict';

Object.equals = function(x, y) {
    // If both x and y are null or undefined and exactly the same
    if (x === y) return true;

    // If they are not strictly equal, they both need to be Objects
    if (!(x instanceof Object) || !(y instanceof Object)) return false;

    // They must have the exact same prototype chain,
    // the closest we can do is test there constructor.
    if (x.constructor !== y.constructor) return false;

    for (var p in x) {
        // Other properties were tested using x.constructor === y.constructor
        if (!x.hasOwnProperty( p )) continue;

        // Allows to compare x[ p ] and y[ p ] when set to undefined
        if (!y.hasOwnProperty( p )) return false;

        // If they have the same strict value or identity then they are equal
        if (x[ p ] === y[ p ]) continue;

        // Numbers, Strings, Functions, Booleans must be strictly equal
        if (typeof( x[ p ] ) !== "object") return false;

        // Objects and Arrays must be tested recursively
        if (!Object.equals( x[ p ],  y[ p ] )) return false;
    }

    for (p in y) {
        // Allows x[ p ] to be set to undefined
        if (y.hasOwnProperty( p ) && ! x.hasOwnProperty( p )) return false;
    }
    return true;
}

Object.clone = function(another) {
    return JSON.parse(JSON.stringify(another));
}

describe('TGAMChart.adapter, Testing chart adapter.', function() {

    const assert = require('assert');
    let api, adapter;
    before(()=>{
        api = {};
        adapter = require('../adapter.js')(api);
    });

    it('Input is empty.', function(){
        const input = [];
        const output = adapter([]);
        assert(output);
        assert.equal(true, Object.equals(input, output));
    });

    const periods = [
        {since: 'Sat May 27 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Sat May 27 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Sun May 28 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Sun May 28 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Mon May 29 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Mon May 29 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Tue May 30 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Tue May 30 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Wed May 31 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Wed May 31 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Thu Jun 01 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Thu Jun 01 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Fri Jun 02 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Fri Jun 02 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Sat Jun 03 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Sat Jun 03 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Sun Jun 04 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Sun Jun 04 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Mon Jun 05 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Mon Jun 05 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Tue Jun 06 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Tue Jun 06 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Wed Jun 07 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Wed Jun 07 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Thu Jun 08 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Thu Jun 08 2017 23:59:59 GMT+0300 (MSK)' },

        {since: 'Fri Jun 09 2017 00:00:00 GMT+0300 (MSK)',
         till: 'Fri Jun 09 2017 23:59:59 GMT+0300 (MSK)' }
    ];

    it('1 element.', function(){
        const input = [];
        for (let i=0; i<1; ++i) {
            input.push({time:periods[i].since, value:100*(i+1)});
        }
        const output = adapter(input);
        assert.equal(true, Object.equals(input, output));
    });

    it('Many element.', function(){
        const input = [];
        for (let i=0; i<periods.length; ++i) {
            input.push({time:periods[i].since, value:100*(i+1)});
        }
        const output = adapter(input);
        assert.equal(true, Object.equals(input, output));
    });

    describe('Failures.', function() {

        it('No input.', function() {
            let err;
            try {
               const output = adapter();
            } catch(e) { err=e; }
            assert(err);
            assert.equal('No input is given', err.message);
        });

        it('Incorrect typeof input.', function() {
            let err;
            try {
               const output = adapter({});
            } catch(e) { err=e; }
            assert(err);
            assert.equal('input shall be type of Array', err.message);
        });

        it('Incorrect typeof input.element.', function() {
            let err;
            try { 
               const output = adapter([[]]);
            } catch(e) { err=e; }
            assert(err);
            assert.equal('input.element shall be type of object', err.message);
        });

        it('Incorrect length of input.element.', function() {
            let err;
            try { 
               const output = adapter([{val1:1, val2:2, val3:3}]);
            } catch(e) { err=e; }
            assert(err);
            assert.equal('input.element shall be size of 2', err.message);
        });

        it('Incorrect typeof of input.element.time.', function() {
            let err;
            try { 
               const output = adapter([{time:100, value:'200'}]);
            } catch(e) { err=e; }
            assert(err);
            assert.equal('input.element.time shall be type of string', err.message);
        });

        it('Incorrect typeof of input.element.value.', function() {
            let err;
            try { 
               const output = adapter([{time:'100', value:'200'}]);
            } catch(e) { err=e; }
            assert(err);
            assert.equal('input.element.value shall be type of number', err.message);
        });

    });

});

