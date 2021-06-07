var app=angular.module('myapp',[]);
	app.controller('CartForm', function($scope)
    {
    $scope.cart = {
        items: [{ qty: '', description: '', cost: ''}]
    }

    $scope.addItem = function() {
        $scope.cart.items.push({ qty: '', description: '', cost: ''});
    }

    $scope.removeItem = function(index) {
        $scope.cart.items.splice(index, 1);
    }

    $scope.total = function() {
        var total = 0;
        angular.forEach($scope.cart.items, function(item) {
            total += item.qty * item.cost;
        })
        return total;
    }
}
);
