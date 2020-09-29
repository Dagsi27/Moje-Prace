<template>
    <div>
        <Header siteName="Shop List"></Header>
        <ShopList></ShopList>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from '../components/header/HeaderGlobal';
import ShopList from '../components/content/ShopList';
import Footer from '../components/footer/Footer';
export default {

  components: {
    Header,
    ShopList,
    Footer
  }
}
</script>
