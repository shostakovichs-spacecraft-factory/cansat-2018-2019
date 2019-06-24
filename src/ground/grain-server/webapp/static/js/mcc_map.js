var headPoint = undefined;

function addCoord(source, line, point) {
    coordinate = ol.proj.fromLonLat( [point.lon, point.lat ]);
    line.appendCoordinate(coordinate);

    feature = new ol.Feature({
        geometry: new ol.geom.Point(coordinate)
    });

    feature.setId(point.time_usec.toString());
    feature.fix_type = point.fix_type;

    source.addFeature(feature);
}

function updateCoords(mapUpdateData) {
    $.getJSON(mapUpdateData.dataUrl + "?latestUpdateTime=" + mapUpdateData.latestUpdateTime, function(data) {
        console.log("updating map");

        data.forEach( function(point) {
            addCoord(mapUpdateData.source, mapUpdateData.line, point);
            mapUpdateData.latestUpdateTime = point.servertime;
        });
    });

    mapUpdateData.timeoutContext.setTimeout(
        function() { updateCoords(mapUpdateData); },
        updatePeriodMs
    );
}

function mccMapMain(mapDataRootUri) {

    OSM = new ol.source.OSM();
    ArcGIS = new ol.source.TileArcGISRest({
        url: 'http://server.arcgisonline.com/arcgis/rest/services/ESRI_Imagery_World_2D/MapServer'
    });

    var map = new ol.Map({
        layers: [
            new ol.layer.Tile({
                source: OSM
            })
        ],
        target: 'map',
        controls: ol.control.defaults({
          attributionOptions: {
            collapsible: false
          }
        }),
        view: new ol.View({
          center: [4209258.894783431, 7543688.893557276],
          zoom: 17
        })
    });


    var vector = new ol.layer.Vector({
        source: new ol.source.Vector({wrapX: false}),
        style: new ol.style.Style({
          fill: new ol.style.Fill({
            color: 'rgba(255, 255, 255, 0.2)'
          }),
          stroke: new ol.style.Stroke({
            color: '#ffcc33',
            width: 2
          }),
          image: new ol.style.Circle({
            radius: 3,
            fill: new ol.style.Fill({
              color: '#ff9933'
            })
          })
        })
    });

    map.addLayer(vector);


    var line = new ol.geom.LineString([]);

    var lineFeature = new ol.Feature({
        geometry: line,
        name: 'Line'
    });

    vector.getSource().addFeature(lineFeature);


    var popup = new ol.Overlay({
        element: document.getElementById('popup')
    });
    map.addOverlay(popup);


    select = new ol.interaction.Select({
        condition: ol.events.condition.pointerMove,
        filter: function(feature, layer) {
            if(feature.getGeometry().getType() == 'Point') return true;
            return false;
        }
    });

    select.on('select', function(evt) {
        var element = popup.getElement();
        $(element).popover('hide');

        evt.selected.forEach( function(feature) {
            popup.setPosition(feature.getGeometry().getCoordinates());
            $(element).popover({
                'placement': 'top',
                'animation': false,
                'html': true
            });

            $(element).data('bs.popover').config.content = '<p>Fix:' + feature.fix_type.toString() + '</p>'
            $(element).popover('show');

        });
    });

    map.addInteraction(select);


    var snap = new ol.interaction.Snap({
        source: vector.getSource()
    });
    map.addInteraction(snap);


    mapUpdateData = {
        source: vector.getSource(),
        line: line,
        dataUrl: mapDataRootUri,
        latestUpdateTime: -1,
        timeoutContext: this
    };

    setTimeout(
        function() { updateCoords(mapUpdateData); },
        updatePeriodMs
    );


    map.render();
}