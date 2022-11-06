'use strict';

(function() {

let assert;
if (typeof module !== 'undefined') {
    // Node support
    assert = require('assert');
} else {
    // Browser support
    assert = window.assert;
}

const doExport = function(api) {

    // This adapet converts input data to format recognized by TGAMChart.
    // Actually this adapetr only checks that input conforms expected formats
    // and returns a copy of input, i.e. doesn't perform any conversion.
    //
    // Input:
    //     const input = [
    //         { time: 'Thu Jun 08 2017 23:59:59 GMT+0300 (MSK)', value:100},
    //
    //         ...
    //
    //         { time: 'Fri Jun 09 2017 23:59:59 GMT+0300 (MSK)', value:100}
    //     ];
    //
    // Output:
    //     const output = [
    //         { time: 'Thu Jun 08 2017 23:59:59 GMT+0300 (MSK)', value:100},
    //
    //         ...
    //
    //         { time: 'Fri Jun 09 2017 23:59:59 GMT+0300 (MSK)', value:100}
    //     ];
    //

    const adapter = function(input) {
        assert(input, 'No input is given');
        assert(Array.isArray(input) == true, 'input shall be type of Array');

        const output = JSON.parse(JSON.stringify(input));

        const proceedValuesUiWay = function(values) {
            values.forEach(function(v){if(v.value === undefined)v.value = 0;});
        }
        proceedValuesUiWay(output);

        for(let i=0; i<output.length; ++i) {
            const e = output[i];
            assert.equal('object', typeof e,  'input.element shall be type of object');
            assert(Array.isArray(e) == false, 'input.element shall be type of object');
            assert.equal(2, Object.keys(e).length, 'input.element shall be size of 2');

            assert.equal('string', typeof e.time,  'input.element.time shall be type of string');
            assert.equal('number', typeof e.value, 'input.element.value shall be type of number');
        }

        return output;
    }

    return adapter;
}

if (typeof module !== 'undefined') {
    // Node support
    module.exports = doExport;
} else {
    // Browser support
    window.TGAMChartAdapter = doExport(window.api);
}

})();

