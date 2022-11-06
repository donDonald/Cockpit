'use strict';

(function() {

function assert(condition, message) {
    if (!condition) {
        throw message || "Assertion failed";
    }
}

const log = {
    debug: function(text) {if(0){console.log(text);}},
    dir: function(obj) {if(0){console.dir(obj);}}
}

const Chart = function(domId, width, height, dataSource, yAxisName) {
    log.debug('TGAMChart(), domId:' +
              domId + ', w:' + width + ', h:' + height +
              ', yAxisName:' + yAxisName);

console.log('###########################, dataSource');
console.dir(dataSource);

    assert(dataSource.length > 0, 'TGAMChart(), empty data!');
    const margin = {top: 20, right: 20, bottom: 30, left: 50};
    width = width - margin.left - margin.right,
    height = height - margin.top - margin.bottom;

    const x = d3.scale.ordinal()
        //.domain(d3.range(dataSource.length))
        .domain([0, d3.max(dataSource, (d)=>{ return d.x; } )])
        .rangeRoundBands([0, width], 0.1);

    const y = d3.scale.linear()
        .domain([0, d3.max(dataSource, (d)=>{ return d.y; } )])
        //.range([0, height]);
        .range([height, 0]);

    const xAxis = d3.svg.axis()
        .scale(x)
        .orient("bottom");

    const yAxis = d3.svg.axis()
        .scale(y)
        .orient("left");

    const svg = d3.select("#"+domId).append("svg")
        .attr("width", width + margin.left + margin.right)
        .attr("height", height + margin.top + margin.bottom)
      .append("g")
        .attr("transform", "translate(" + margin.left + "," + margin.top + ")");

 // svg.selectAll("rect")
 //     .data(dataSource)
 //     .enter()
 //     .append("rect")
 //     .attr("class", "TGAMChartPositive")
 //     .attr("width", x.rangeBand())
 //     .attr("height", function(d) { return height - y(d[1]); } )
 //     .attr("x", function(d, i) { return x(i); })
 //     .attr("y", function(d, i) { return y(d[1]); });

    // Create x axis
    svg.append("g")
        .attr("class", "chartAxis")
        .attr("transform", "translate(0," + height + ")")
        .call(xAxis);

    // Create yaxis
    svg.append("g")
        .attr("class", "chartAxis")
        .call(yAxis);
}

window.TGAMChart = Chart;

}());

