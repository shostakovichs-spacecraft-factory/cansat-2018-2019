function updateSpectrum(spectrumUpdateData) {
    $.getJSON(spectrumUpdateData.dataUrl + "?latestIdentifier=" + spectrumUpdateData.latestIdentifier, function(data) {
        console.log("updating spectrum");

        if(data.identifier != spectrumUpdateData.latestIdentifier)
        {
            spectrumUpdateData.chart.data.datasets[0].data = data.data;
            spectrumUpdateData.chart.update();
            spectrumUpdateData.latestIdentifier = data.identifier;
        }

        document.getElementById("spectrum-img").src = spectrumUpdateData.IMGUrl + '?identifier=' +  spectrumUpdateData.latestIdentifier;
    });

    spectrumUpdateData.timeoutContext.setTimeout(
        function() {
             updateSpectrum(spectrumUpdateData);
        },
        updatePeriodSpectrumMs
    );
}

function mccSpectrumMain(spectrumDataUrl, spectrumIMGUrl)
{
    spectrumChart = new Chart(document.getElementById("spectrum-plot-canvas").getContext('2d'), {
        type: 'line',
        data: {
            "datasets": [
                            {
                                "label": "Спектр",
                                "fill": false,
                                "pointRadius": 0,
                                "borderColor": "#f44242",
                                "borderWidth": 2,
                                "lineTension": 0,
                                "data": [],
                            },
                        ]
        },
        options: {
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

    spectrumUpdateData = {
        dataUrl: spectrumDataUrl,
        IMGUrl: spectrumIMGUrl,
        chart: spectrumChart,
        latestIdentifier: -1,
        timeoutContext: this
    };

    setTimeout(
        function() {
             updateSpectrum(spectrumUpdateData);
        },
        updatePeriodSpectrumMs
    );
}