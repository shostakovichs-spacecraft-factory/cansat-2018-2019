
function makeChart(canvasId, datasets) {
    myChart = new Chart(document.getElementById(canvasId).getContext('2d'), {
        type: 'line',
        data: {
            "datasets": datasets
        },
        options: {
            aspectRatio: 1,
            scales: {
                yAxes: [{
                    id: 'y1',
                    type: 'linear',
                }],
                xAxes: [{
                    id: 'x1',
                    type: 'linear',
                    reversed: true,
                }]
            },
            animation: {
                duration: 0, // general animation time
            },
            hover: {
                animationDuration: 0, // duration of animations when hovering an item
            },
                responsiveAnimationDuration: 0, // animation duration after a resize
            },
    });

    return myChart;
}


function updatePlot(chartObject) {

    $.getJSON(chartObject.dataUrl + "&latestUpdateTime=" + chartObject.latestUpdateTime, function(data) {
        console.log("updating plot " + chartObject.name);
        var i;
        for(i = 0; i < data.datas.length; i++) {
            Array.prototype.push.apply(chartObject.chart.data.datasets[i].data, data.datas[i]);
            try {
                while(chartObject.chart.data.datasets[i].data[0].servertime < data.viewlimit)
                        chartObject.chart.data.datasets[i].data.shift();
            } catch(err) {}
        }
        chartObject.chart.update();
        chartObject.latestUpdateTime = data.latestUpdateTime;

        chartObject.timeoutContext.setTimeout(
            function() { updatePlot(chartObject); },
            updatePeriodMs
        );
    });
}


function mccChartsMain(charts, updatePeriodMs, plotDataRootUri) {

    charts = $.map(charts, function(chartObj) {

        chartObj.dataUrl = plotDataRootUri + "?chartName=" + chartObj.name;
        chartObj.latestUpdateTime =  -1;
        chartObj.chart = makeChart(chartObj.name + "-plot-canvas", chartObj.datasets);
        chartObj.timeoutContext = this;

        return chartObj;
    });


    // Графики успешно созданы. Запускаем периодические обновления

    var intervals = $.map(charts, function(chartObj) {
        return setTimeout(
            function() { updatePlot(chartObj); },
            updatePeriodMs
        );
    });

}

