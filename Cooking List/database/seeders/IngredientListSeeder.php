<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use App\Models\IngredientList;

class IngredientListSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        $send=IngredientList::create(
            [
                'user_id' => 1,
                'product' => 'salt',
                'done' => true

            ]
        );
        $send->save();
        $send=IngredientList::create(
            [
                'user_id' => 1,
                'product' => 'apple',
                'done' => false

            ]
        );
        $send->save();
    }
}
