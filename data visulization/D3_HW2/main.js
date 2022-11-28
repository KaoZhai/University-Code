var ptsMin = -1
var ptsMax = 100
var rebMin = -1
var rebMax = 100
var astMin = -1
var astMax = 100
var ageMin = -1
var ageMax = 100
var gpMin = -1
var gpMax = 100
var draMin = -1
var draMax = 100
var selectedData = []
var allData = []
var scatterplotDots
var margin = {top: 10, right: 30, bottom: 30, left: 40}
var ptsCX, ptsCY, ptsHis;
var rebCX, rebCY, rebHis;
var astCX, astCY, astHis;
var ageCX, ageCY, ageHis;
var  gpCX,  gpCY,  gpHis;
var draCX, draCY, draHis;
var namedata = []

function updateData(data, isHis)
{      
    if(!isHis)
    {
        namedata = data
    }

        data = namedata;
        selected = [];
        data.forEach(function(d){
            if(d.pts >= ptsMin && d.pts <= ptsMax)
                selected.push(d);
        })
        data = selected;

        selected = [];
        data.forEach(function(d){
            if(d.reb >= rebMin && d.reb <= rebMax)
                selected.push(d);
        })
        data = selected;

        selected = [];
        data.forEach(function(d){
            if(d.ast >= astMin && d.ast <= astMax)
                selected.push(d);
        })
        data = selected;

        selected = [];
        data.forEach(function(d){
            if(d.age >= ageMin && d.age <= ageMax)
                selected.push(d);
        })
        data = selected;

        selected = [];
        data.forEach(function(d){
            if(d.gp >= gpMin && d.gp <= gpMax)
                selected.push(d);
        })
        data = selected;

        selected = [];
        data.forEach(function(d){
            if(d.draft_number >= draMin && d.draft_number <= draMax)
                selected.push(d);
        })
        selectedData = selected;
}

function transScatterPlot()
{
    var t = d3.transition()
              .duration(1000);
    
    var dots = scatterplotDots

    dots.transition(t)
    .style('opacity', d => {
    var apear = false;
    selectedData.forEach(function(sd){
        if(d.player_name == sd.player_name){
            apear = true;
        }
    });
    if(apear)
        return "1";
    else
        return "0.3";
    })  
}

function transPtsHis()
{
    var t = d3.transition()
              .duration(1000);

    var sbin = ptsHis(selectedData);

    d3.select('#ptsData')
      .selectAll('rect')
      .data(sbin).transition(t)
      .attr("transform", function(d) { return "translate(" + (margin.left + ptsCX(d.x0)) + "," + (margin.top + (ptsCY(d.length)) + ")");})
      .attr("height", d =>  (150 - ptsCY(d.length)) );
}

function transRebHis(){
    var t = d3.transition()
              .duration(1000);

    var sbin = rebHis(selectedData);

    d3.select('#rebData')
      .selectAll('rect')
      .data(sbin).transition(t)
      .attr("transform", function(d) { return "translate(" + ((margin.left+350) + rebCX(d.x0)) + "," + (margin.top + (rebCY(d.length)) + ")");})
      .attr("height", d =>  (150 - rebCY(d.length)) );
}

function transAstHis(){
    var t = d3.transition()
              .duration(1000);

    var sbin = astHis(selectedData);

    d3.select('#astData')
      .selectAll('rect')
      .data(sbin).transition(t)
      .attr("transform", function(d) { return "translate(" + ((margin.left+700) + astCX(d.x0)) + "," + (margin.top + (astCY(d.length)) + ")");})
      .attr("height", d =>  (150 - astCY(d.length)) );
}

function transAgeHis()
{
    var t = d3.transition()
              .duration(1000);

    var sbin = ageHis(selectedData);

    d3.select('#ageData')
      .selectAll('rect')
      .data(sbin).transition(t)
      .attr("transform", function(d) { return "translate(" + (margin.left + ageCX(d.x0)) + "," + ((margin.top+200) + (ageCY(d.length)) + ")");})
      .attr("height", d =>  (150 - ageCY(d.length)) );
}

function transGpHis()
{
    var t = d3.transition()
              .duration(1000);

    var sbin = gpHis(selectedData);

    d3.select('#gpData')
      .selectAll('rect')
      .data(sbin).transition(t)
      .attr("transform", function(d) { return "translate(" + (margin.left+350 + gpCX(d.x0)) + "," + ((margin.top+200) + (gpCY(d.length)) + ")");})
      .attr("height", d =>  (150 - gpCY(d.length)) );
}

function transDraHis()
{
    var t = d3.transition()
              .duration(1000);

    var sbin = draHis(selectedData);

    d3.select('#draData')
      .selectAll('rect')
      .data(sbin).transition(t)
      .attr("transform", function(d) { return "translate(" + (margin.left+700 + draCX(d.x0)) + "," + ((margin.top+200) + (draCY(d.length)) + ")");})
      .attr("height", d =>  (150 - draCY(d.length)) );
}

function updatePicture(){
    transScatterPlot();
    transPtsHis();
    transRebHis();
    transAstHis();
    transAgeHis();
    transGpHis();
    transDraHis();
}

function drawScatterplot(data)
{
    var avgMin = d3.min(data, d=>(d.ptsNorm + d.rebNorm + d.astNorm)/3)
    var avgMax = d3.max(data, d=>(d.ptsNorm + d.rebNorm + d.astNorm)/3)

    rScale = d3.scaleLinear()
               .domain([avgMin, avgMax])
               .range([3, 8]);
    
    var xPosMin = d3.min(data, d=>(d.umapX));
    var xPosMax = d3.max(data, d=>(d.umapX));
    var yPosMin = d3.min(data, d=>(d.umapY));
    var yPosMax = d3.max(data, d=>(d.umapY));

    xScale = d3.scaleLinear()
               .domain([xPosMin, xPosMax])
               .range([0, 450]);
    
    yScale = d3.scaleLinear()
               .domain([yPosMin, yPosMax])
               .range([450, 0]);

    var Xaxis = d3.axisBottom(xScale).tickFormat("");
    var Yaxis = d3.axisLeft(yScale).tickFormat("");

    const svg = d3.select('body')
                  .append('svg')
                  .attr("width", 470)
                  .attr("height", 470);
    
    var brushG = svg.append("g")
                  .attr('id', 'brushG')
                  .attr("transform", `translate(${10}, 0)`)

    var dotG = svg.append("g")
                  .attr('id', 'scatterplot')
        
    var dots = dotG.selectAll('dot')
            .data(data)
            .enter().append('circle')
            .attr('cx', d => xScale(d.umapX))
            .attr('cy', d => yScale(d.umapY))
            .attr('r', d => rScale((d.ptsNorm + d.rebNorm + d.astNorm)/3))
            .style('fill', d => {
                if(d.ptsNorm >= d.rebNorm && d.ptsNorm >= d.astNorm)
                    return "red";
                else if(d.rebNorm >= d.ptsNorm && d.rebNorm >= d.astNorm)
                    return "green";
                else
                    return "blue"})
            .style('opacity', d => {
                if(selectedData.length == 0)
                    return 1;
                var apear = false;
                selectedData.forEach(function(sd){
                    if(d.player_name == sd.player_name){
                        apear = true;
                    }
                });
                if(apear)
                    return "1";
                else
                    return "0.3";
            })
            .attr("transform", `translate(${10}, 0)`);

    scatterplotDots = dots;
    var brush = d3.brush()
                  .extent([[0, 0], [450, 450]])
                  .on("start", brushed)
                  .on("brush", brushed);
    
    brushG.call(brush);
    function all() {
        updateData(data, false);
        updatePicture();
    }

    function brushed() {
        var extent = d3.event.selection;
        selected = []
        if((extent[1][0] - extent[0][0] < 0.1) && (extent[1][1] - extent[0][1] < 0.1)){
            updateData(data, false);
            updatePicture();
        }else{
        data.forEach(function(d){
            if(xScale(d.umapX) >= extent[0][0] &&
            xScale(d.umapX) <= extent[1][0] &&
            yScale(d.umapY) >= extent[0][1] &&
            yScale(d.umapY) <= extent[1][1]){
                selected.push(d);
            }
        })
        updateData(selected, false);
        updatePicture();}
    }
    
    var tip = d3.tip()
                .attr('class', 'd3-tip')
                .html(d=>("name: " + d.player_name + " pts: " + d.pts + " reb: " + d.reb + " ast: " + d.ast));
    
    dotG.call(tip);
                
    dots.on('mouseover', tip.show)
        .on('mouseout', tip.hide);

    const g = svg.append("g").attr("transform", `translate(${10}, 0)`);
    g.append("g").attr("transform", `translate(0, ${450})`).call(Xaxis)
    g.append("g").call(Yaxis)
    
    var data_legend = [
        {
            "name" : "pts",
            "color": "red"
        },
        {
            "name" : "reb",
            "color": "green"
        },
        {
            "name" : "ast",
            "color": "blue"
        }
    ]
    
    var legend = svg.selectAll(".legend")
                    .data(data_legend)
                    .enter().append('g')
                    .attr("class", "legend")
                    .attr("transform", function(d, i) { return "translate(0," + (i * 20) + ")";});
    
    legend.append("circle")
          .attr("cx", 20)
          .attr("cy", 20)
          .attr("r", 4)
          .attr("width", 40)
          .style("fill", function(d){
            return d.color
          });
    
    legend.append("text")
          .attr("x", 60)
          .attr("y", 24)
          .style("text-anchor", "end")
          .text(function(d){
            return d.name;
          });
    
    svg.append('g')
       .attr("class", "legend")
       .attr("transform", "translate(0,60)")
       .append("text")
       .attr("x", 64)
       .attr("y", 24)
       .style("text-anchor", "end")
       .text("r:　avg");
    
    
}

function drawPts(data)
{
    const ptsG = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
                  .attr("id", "pts")
    var minX = d3.min(data, d =>(d.pts));
    var maxX = d3.max(data, d =>(d.pts));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    ptsCX = x;
    ptsG.append("g")
       .attr("transform", "translate(" + margin.left + "," + (margin.top + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.pts;})
                         .domain(x.domain())
                         .thresholds(x.ticks(31));
    ptsHis = histogram;

    var bin = histogram(data);
    var sbin = histogram(selectedData);

    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    ptsCY = y;
    ptsG.append("g")
       .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
       .call(d3.axisLeft(y))
    
    var brush = d3.brushX()
                  .extent([[0, 0], [300, 150]])
                  .on("start", brushed)
                  .on("brush", brushed);
    
    function brushed() {
        var extent = d3.event.selection;
        var Xrate = (maxX - minX) / 300;
        var minData = Xrate * extent[0];
        var maxData = Xrate * extent[1];
        ptsMin = minData
        ptsMax = maxData
        if(ptsMax - ptsMin < 0.01)
        {
            ptsMax = 100;
            ptsMin = -1;
        }
        updateData(data, true);
        updatePicture();
    }

    ptsG.append("g")
        .selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + (margin.left + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "white")
        .style("stroke", "black");

    ptsR = ptsG.append("g")
        .attr("id", "ptsData")
        .selectAll("rect")
    
    ptsR.data(sbin).enter()
        .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + (margin.left + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");

    ptsG.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + (margin.left+150) + "," + margin.top + ")")
       .text("pts");
    
    ptsG.append("g")
       .attr("id", "ptsbrush")
       .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
       .call(brush);
}

function drawReb(data)
{
    const rebG = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
                  .attr("id", "reb")
    var minX = d3.min(data, d =>(d.reb));
    var maxX = d3.max(data, d =>(d.reb));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    rebCX = x;
    rebG.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + (margin.top + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.reb;})
                         .domain(x.domain())
                         .thresholds(x.ticks(31));
    rebHis = histogram;

    var bin = histogram(data);
    var sbin = histogram(selectedData);

    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    rebCY = y;
    rebG.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + margin.top + ")")
       .call(d3.axisLeft(y))
    
    var brush = d3.brushX()
                  .extent([[0, 0], [300, 150]])
                  .on("start", brushed)
                  .on("brush", brushed);
    
    function brushed() {
        var extent = d3.event.selection;
        var Xrate = (maxX - minX) / 300;
        var minData = Xrate * extent[0];
        var maxData = Xrate * extent[1];
        rebMin = minData
        rebMax = maxData
        if(rebMax - rebMin < 0.01)
        {
            rebMax = 100;
            rebMin = -1;
        }
        updateData(data, true);
        updatePicture();
    }

    rebG.append("g")
        .selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+350) + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "white")
        .style("stroke", "black");

    rebR = rebG.append("g")
        .attr("id", "rebData")
        .selectAll("rect")
    
    rebR.data(sbin).enter()
        .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+350) + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");

    rebG.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+350)+150) + "," + margin.top + ")")
       .text("reb");
    
    rebG.append("g")
       .attr("id", "rebbrush")
       .attr("transform", "translate(" + (margin.left+350) + "," + margin.top + ")")
       .call(brush);
}

function drawAst(data)
{
    const astG = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
                  .attr("id", "ast")
    var minX = d3.min(data, d =>(d.ast));
    var maxX = d3.max(data, d =>(d.ast));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    astCX = x;
    astG.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + (margin.top + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.ast;})
                         .domain(x.domain())
                         .thresholds(x.ticks(31));
    astHis = histogram;

    var bin = histogram(data);
    var sbin = histogram(selectedData);

    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    astCY = y;
    astG.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + margin.top + ")")
       .call(d3.axisLeft(y))
    
    var brush = d3.brushX()
                  .extent([[0, 0], [300, 150]])
                  .on("start", brushed)
                  .on("brush", brushed);
    
    function brushed() {
        var extent = d3.event.selection;
        var Xrate = (maxX - minX) / 300;
        var minData = Xrate * extent[0];
        var maxData = Xrate * extent[1];
        astMin = minData
        astMax = maxData
        if(astMax - astMin < 0.01)
        {
            astMax = 100;
            astMin = -1;
        }
        updateData(data, true);
        updatePicture();
    }

    astG.append("g")
        .selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+700) + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "white")
        .style("stroke", "black");

    astR = astG.append("g")
        .attr("id", "astData")
        .selectAll("rect")
    
    astR.data(sbin).enter()
        .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+700) + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");

    astG.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+700)+150) + "," + margin.top + ")")
       .text("ast");
    
    astG.append("g")
       .attr("id", "astbrush")
       .attr("transform", "translate(" + (margin.left+700) + "," + margin.top + ")")
       .call(brush);
}

function drawAge(data)
{
    const ageG = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
                  .attr("id", "age")
    var minX = d3.min(data, d =>(d.age));
    var maxX = d3.max(data, d =>(d.age));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    ageCX = x;
    ageG.append("g")
       .attr("transform", "translate(" + margin.left + "," + ((margin.top + 200) + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.age;})
                         .domain(x.domain())
                         .thresholds(x.ticks(31));
    ageHis = histogram;

    var bin = histogram(data);
    var sbin = histogram(selectedData);

    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    ageCY = y;
    ageG.append("g")
       .attr("transform", "translate(" + margin.left + "," + (margin.top + 200) + ")")
       .call(d3.axisLeft(y))
    
    var brush = d3.brushX()
                  .extent([[0, 0], [300, 150]])
                  .on("start", brushed)
                  .on("brush", brushed);
    
    function brushed() {
        var extent = d3.event.selection;
        var Xrate = (maxX - minX) / 300;
        var minData = Xrate * extent[0];
        var maxData = Xrate * extent[1];
        ageMin = minData
        ageMax = maxData
        if(ageMax - ageMin < 0.01)
        {
            ageMax = 100;
            ageMin = -1;
        }
        updateData(data, true);
        updatePicture();
    }

    ageG.append("g")
        .selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + (margin.left + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "white")
        .style("stroke", "black");

    ageR = ageG.append("g")
        .attr("id", "ageData")
        .selectAll("rect")
    
    ageR.data(sbin).enter()
        .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + (margin.left + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");

    ageG.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + (margin.left+150) + "," + (margin.top + 200) + ")")
       .text("age");
    
    ageG.append("g")
       .attr("id", "agebrush")
       .attr("transform", "translate(" + margin.left + "," + (margin.top + 200) + ")")
       .call(brush);
}

function drawGp(data)
{
    const gpG = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
                  .attr("id", "gp")
    var minX = d3.min(data, d =>(d.gp));
    var maxX = d3.max(data, d =>(d.gp));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    gpCX = x;
    gpG.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + ((margin.top + 200) + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.gp;})
                         .domain(x.domain())
                         .thresholds(x.ticks(31));
    gpHis = histogram;

    var bin = histogram(data);
    var sbin = histogram(selectedData);

    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    gpCY = y;
    gpG.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + (margin.top + 200) + ")")
       .call(d3.axisLeft(y))
    
    var brush = d3.brushX()
                  .extent([[0, 0], [300, 150]])
                  .on("start", brushed)
                  .on("brush", brushed);
    
    function brushed() {
        var extent = d3.event.selection;
        var Xrate = (maxX - minX) / 300;
        var minData = Xrate * extent[0];
        var maxData = Xrate * extent[1];
        gpMin = minData
        gpMax = maxData
        if(gpMax - gpMin < 0.01)
        {
            gpMax = 100;
            gpMin = -1;
        }
        updateData(data, true);
        updatePicture();
    }

    gpG.append("g")
        .selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+350) + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "white")
        .style("stroke", "black");

    gpR = gpG.append("g")
        .attr("id", "gpData")
        .selectAll("rect")
    
    gpR.data(sbin).enter()
        .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+350) + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");

    gpG.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+350)+150) + "," + (margin.top + 200) + ")")
       .text("gp");
    
    gpG.append("g")
       .attr("id", "gpbrush")
       .attr("transform", "translate(" + (margin.left+350) + "," + (margin.top + 200) + ")")
       .call(brush);
}

function drawDraft_number(data)
{
    const draG = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
                  .attr("id", "dra")
    var minX = d3.min(data, d =>(d.draft_number));
    var maxX = d3.max(data, d =>(d.draft_number));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    draCX = x;
    draG.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + ((margin.top + 200) + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.draft_number;})
                         .domain(x.domain())
                         .thresholds(x.ticks(31));
    draHis = histogram;

    var bin = histogram(data);
    var sbin = histogram(selectedData);

    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    draCY = y;
    draG.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + (margin.top + 200) + ")")
       .call(d3.axisLeft(y))
    
    var brush = d3.brushX()
                  .extent([[0, 0], [300, 150]])
                  .on("start", brushed)
                  .on("brush", brushed);
    
    function brushed() {
        var extent = d3.event.selection;
        var Xrate = (maxX - minX) / 300;
        var minData = Xrate * extent[0];
        var maxData = Xrate * extent[1];
        draMin = minData
        draMax = maxData
        if(draMax - draMin < 0.01)
        {
            draMax = 100;
            draMin = -1;
        }
        updateData(data, true);
        updatePicture();
    }

    draG.append("g")
        .selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+700) + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "white")
        .style("stroke", "black");

    draR = draG.append("g")
        .attr("id", "draData")
        .selectAll("rect")
    
    draR.data(sbin).enter()
        .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+700) + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");

    draG.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+700)+150) + "," + (margin.top + 200) + ")")
       .text("draft_number");
    
    draG.append("g")
       .attr("id", "drabrush")
       .attr("transform", "translate(" + (margin.left+700) + "," + (margin.top + 200) + ")")
       .call(brush);
}

function drawHistograms(data)
{
    drawPts(data);
    drawReb(data);
    drawAst(data);
    drawAge(data);
    drawGp(data);
    drawDraft_number(data);
}

d3.csv("NBA1516.csv").then(data => {
    
    // turn string into number
    data.forEach(function(d){
        d.age          = Number(d.age);
        d.ast          = Number(d.ast);
        d.astNorm      = Number(d.astNorm);
        if(d.draft_number == "Undrafted")
            d.draft_number = 64;
        else
            d.draft_number = Number(d.draft_number);
        d.gp           = Number(d.gp);
        d.pts          = Number(d.pts);
        d.ptsNorm      = Number(d.ptsNorm);
        d.reb          = Number(d.reb);
        d.rebNorm      = Number(d.rebNorm);
        d.ptsNorm      = Number(d.ptsNorm);
        d.umapX        = Number(d.umapX);
        d.umapY        = Number(d.umapY);
        allData.push(d)
        selectedData.push(d)
    });

    drawScatterplot(data);

    d3.select('body')
      .append('svg')
      .attr("id", "map")
      .attr("width", 800)
      .attr("height", 450);

    drawUS(data);
    
    d3.select('body')
      .append('svg')
      .attr("id", "his")
      .attr("width", 1200)
      .attr("height", 500);
    
    drawHistograms(data);
    

}).catch(function(error){
    console.log(error)
});

function drawUS(playerData)
{
    d3.json("us-states.json").then(US=>{
        var width = 800;
        var height = 450;

        var projection = d3.geoEquirectangular()
                        .fitExtent([[0, 0], [width, height]], US);
        var geoGenerator = d3.geoPath()
                            .projection(projection);
        
        var paths = d3.select('#map')
                    .selectAll('path')
                    .data(US.features)
                    .enter()
                    .append('path')
                    .attr('stroke', "black")
                    .attr('fill', 'white')
                    .attr('d', geoGenerator);
        
        d3.csv("TeamLoc.csv").then(LocData=>{
            LocData.forEach(function(d){
                d.lon = Number(d.lon);
                d.lat = Number(d.lat);
                
                var num = 0;
                playerData.forEach(function(playerD){
                    if(playerD.team_abbreviation == d.team_abbreviation)
                        num++;
                })

                d3.select('#map')
                  .append('g')
                  .append('circle')
                  .attr('cx', projection([d.lon, d.lat])[0])
                  .attr('cy', projection([d.lon, d.lat])[1])
                  .attr('r', num)
                  .attr('stroke', 'black')
                  .attr('fill', 'red')
                  .attr('opacity', 0.5)
                  .attr('d', geoGenerator)
                
                d3.select('#map')
                  .append('text')
                  .attr('transform', 'translate (' + projection([d.lon, d.lat])[0] + ',' + projection([d.lon, d.lat])[1] + ')')
                  .text(d.team_abbreviation)
            });
        });
    });
}