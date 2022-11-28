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
               .range([0, 400]);
    
    yScale = d3.scaleLinear()
               .domain([yPosMin, yPosMax])
               .range([400, 0]);

    var Xaxis = d3.axisBottom(xScale).tickFormat("");
    var Yaxis = d3.axisLeft(yScale).tickFormat("");

    const svg = d3.select('body')
                  .append('svg')
                  .attr("width", 450)
                  .attr("height", 450)
                  .attr("transform", `translate(${10}, 0)`);
    
    const g = svg.append("g").attr("transform", `translate(${10}, 0)`);
    
    svg.append("g")
        .selectAll('dot')
        .data(data)
        .enter()
        .append('circle')
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
        .attr("transform", `translate(${10}, 0)`);
    
    g.append("g").attr("transform", `translate(0, ${400})`).call(Xaxis)
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
};

function drawPts(data)
{
    var margin = {top: 10, right: 30, bottom: 30, left: 40}

    const svg = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
    var minX = d3.min(data, d =>(d.pts));
    var maxX = d3.max(data, d =>(d.pts));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    svg.append("g")
       .attr("transform", "translate(" + margin.left + "," + (margin.top + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.pts;})
                         .domain(x.domain())
                         .thresholds(x.ticks(40));
    var bin = histogram(data);
    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    svg.append("g")
       .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
       .call(d3.axisLeft(y))
    svg.selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + (margin.left + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");
    svg.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + (margin.left+150) + "," + margin.top + ")")
       .text("pts");
};

function drawReb(data)
{
    var margin = {top: 10, right: 30, bottom: 30, left: 40}

    const svg = d3.select('#his')
                  .append('g')   
                  .attr("width", 350)
                  .attr("height", 200)
    var minX = d3.min(data, d =>(d.reb));
    var maxX = d3.max(data, d =>(d.reb));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + (margin.top + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.reb;})
                         .domain(x.domain())
                         .thresholds(x.ticks(40));
    var bin = histogram(data);
    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + margin.top + ")")
       .call(d3.axisLeft(y))
    svg.selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+350) + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/40 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");
    svg.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+350)+150) + "," + margin.top + ")")
       .text("reb");
}

function drawAst(data)
{
    var margin = {top: 10, right: 30, bottom: 30, left: 40}

    const svg = d3.select('#his')
                  .append('g')   
                  .attr("width", 350)
                  .attr("height", 200)
    var minX = d3.min(data, d =>(d.ast));
    var maxX = d3.max(data, d =>(d.ast));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + (margin.top + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.ast;})
                         .domain(x.domain())
                         .thresholds(x.ticks(25));
    var bin = histogram(data);
    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + margin.top + ")")
       .call(d3.axisLeft(y))
    svg.selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+700) + x(d.x0)) + "," + (margin.top + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/25 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");
    svg.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+700)+150) + "," + margin.top + ")")
       .text("ast");
}

function drawAge(data)
{
    var margin = {top: 10, right: 30, bottom: 30, left: 40}

    const svg = d3.select('#his')
                  .append('g')
                  .attr("width", 350)
                  .attr("height", 200)
    var minX = d3.min(data, d =>(d.age));
    var maxX = d3.max(data, d =>(d.age));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    svg.append("g")
       .attr("transform", "translate(" + margin.left + "," + ((margin.top + 200) + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.age;})
                         .domain(x.domain())
                         .thresholds(x.ticks(40));
    var bin = histogram(data);
    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    svg.append("g")
       .attr("transform", "translate(" + margin.left + "," + (margin.top + 200) + ")")
       .call(d3.axisLeft(y))
    svg.selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + (margin.left + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", 14)
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");
    svg.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + (margin.left+150) + "," + (margin.top + 200) + ")")
       .text("age");
};

function drawGp(data)
{
    var margin = {top: 10, right: 30, bottom: 30, left: 40}

    const svg = d3.select('#his')
                  .append('g')   
                  .attr("width", 350)
                  .attr("height", 200)
    var minX = d3.min(data, d =>(d.gp));
    var maxX = d3.max(data, d =>(d.gp));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + ((margin.top + 200) + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.gp;})
                         .domain(x.domain())
                         .thresholds(x.ticks(60));
    var bin = histogram(data);
    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+350) + "," + (margin.top + 200) + ")")
       .call(d3.axisLeft(y))
    svg.selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+350) + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", function(d) { return 300.0/60 ; })
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");
    svg.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+350)+150) + "," + (margin.top + 200) + ")")
       .text("gp");
}

function drawDraft_number(data)
{
    var margin = {top: 10, right: 30, bottom: 30, left: 40}

    const svg = d3.select('#his')
                  .append('g')   
                  .attr("width", 350)
                  .attr("height", 200)
    var minX = d3.min(data, d =>(d.draft_number));
    var maxX = d3.max(data, d =>(d.draft_number));
    var x = d3.scaleLinear()
                 .domain([minX, maxX])
                 .range([0, 300]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + ((margin.top + 200) + 150) + ")")
       .call(d3.axisBottom(x));
    
    var histogram = d3.histogram()
                         .value(function(d){return d.draft_number;})
                         .domain(x.domain())
                         .thresholds(x.ticks(10));
    var bin = histogram(data);
    var y = d3.scaleLinear()
                 .domain([0, d3.max(bin, function(d){return d.length;})])
                 .range([150, 0]);
    svg.append("g")
       .attr("transform", "translate(" + (margin.left+700) + "," + (margin.top + 200) + ")")
       .call(d3.axisLeft(y))
    svg.selectAll("rect")
       .data(bin)
       .enter()
       .append("rect")
        .attr("x", 1)
        .attr("transform", function(d) { return "translate(" + ((margin.left+700) + x(d.x0)) + "," + ((margin.top + 200) + (y(d.length)) + ")");})
        .attr("width", 17)
        .attr("height", function(d) { return 150 - y(d.length); })
        .style("fill", "#69b3a2");
    svg.append("g")
       .attr("cleass", "label")
       .append("text")
       .attr("transform", "translate(" + ((margin.left+700)+150) + "," + (margin.top + 200) + ")")
       .text("draft_number");
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


d3.csv("TeamLoc.csv").then(data => {
    // r:
}).catch(function(error){
    console.log(error)
});

