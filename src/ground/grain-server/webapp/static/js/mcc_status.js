var statusToText=["Booting", "Ready", "Loaded", "Free fall", "Awaiting chute", "Pre-landing", "Landed"];

function updateStatus(statusUpdateData) {
    $.getJSON(statusUpdateData.dataUrl, function(data) {
        console.log("updating status");

        text = statusToText[data.status];

        $("#status-div").text(text)
    });

    statusUpdateData.timeoutContext.setTimeout(
        function() {
             updateModel(statusUpdateData);
        },
        updatePeriodStatusMs
    );
}

function mccStatusMain(dataUrl)
{
    statusUpdateData = {
        dataUrl: dataUrl,
        timeoutContext: this
    }

    setTimeout(
        function() {
             updateStatus(statusUpdateData);
        },
        updatePeriodStatusMs
    );
}