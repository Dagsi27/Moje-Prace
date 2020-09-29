<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/
Route::prefix('api')->group(function(){
    Route::get('ingredient','IngredientListController@index')->name('IngredientListController.index');
    Route::post('ingredient', 'IngredientListController@store')->name('IngredientListController.store');
    Route::post('ingredient/update', 'IngredientListController@update')->name('IngredientListController.update');
    Route::post('ingredient/delete', 'IngredientListController@delete')->name('IngredientListController.delete');

    Route::get('/testy',function(){
        return "welcome";
    });

    Route::prefix('auth')->group(function(){
        Route::get('init', 'AuthController@init');

        Route::post('login', 'AuthController@login');
        Route::post('register', 'AuthController@register');
        Route::post('logout', 'AuthController@logout');
    });
});

Route::get('/', function () {
    return view('welcome');
});

Route::get('/{any}', function ($any) {
    return view('welcome');
})->where('any', '.*');

